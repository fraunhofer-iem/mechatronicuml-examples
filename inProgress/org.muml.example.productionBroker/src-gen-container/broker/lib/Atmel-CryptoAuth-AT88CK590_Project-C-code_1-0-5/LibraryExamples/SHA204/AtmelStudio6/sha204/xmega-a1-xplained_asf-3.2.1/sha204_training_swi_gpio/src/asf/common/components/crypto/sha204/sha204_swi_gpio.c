/*
 * \file
 *
 * \brief ATSHA204 file that implements the I2C layer for the device
 *
 *
 * Copyright (c) 2011-2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */
#include <asf.h>
#include "swi_phys.h"                         // hardware dependent declarations for SWI
#include "sha204_physical.h"                  // declarations that are common to all interface implementations
#include "sha204_lib_return_codes.h"          // declarations of function return codes
#include "sha204_timer.h"                     // definitions for TC based delay functions

#define SHA204_SWI_FLAG_CMD     ((uint8_t) 0x77) //!< flag preceding a command
#define SHA204_SWI_FLAG_TX      ((uint8_t) 0x88) //!< flag requesting a response
#define SHA204_SWI_FLAG_IDLE    ((uint8_t) 0xBB) //!< flag requesting to go into Idle mode
#define SHA204_SWI_FLAG_SLEEP   ((uint8_t) 0xCC) //!< flag requesting to go into Sleep mode


/** \brief This SWI function initializes the hardware.
 */
void sha204p_init(void)
{
	// Initialize timer.
	sha204h_timer_init();

	// Initialize interrupt vectors.
	irq_initialize_vectors();

	// Enable interrupts.
	cpu_irq_enable();

	// Configure communication pin.
	swi_enable();
}


/** \brief This SWI function selects the GPIO pin used for communication.
 *
 * \param[in] id index into array of pins
 */
void sha204p_set_device_id(uint8_t id)
{
	swi_set_device_id(id);
}


/** \brief This SWI function sends a command to the device.
 * \param[in] count number of bytes to send
 * \param[in] command pointer to command buffer
 * \return status of the operation
 */
uint8_t sha204p_send_command(uint8_t count, uint8_t *command)
{
	uint8_t ret_code = swi_send_byte(SHA204_SWI_FLAG_CMD);
	if (ret_code != SWI_FUNCTION_RETCODE_SUCCESS)
		return SHA204_COMM_FAIL;

	return swi_send_bytes(count, command);
}


/** \brief This SWI function receives a response from the device.
 * \param[in] size number of bytes to receive
 * \param[out] response pointer to response buffer
 * \return status of the operation
 */
uint8_t sha204p_receive_response(uint8_t size, uint8_t *response)
{
	uint8_t count_byte;
	uint8_t i;
	uint8_t ret_code;

	for (i = 0; i < size; i++)
		response[i] = 0;

	(void) swi_send_byte(SHA204_SWI_FLAG_TX);

	ret_code = swi_receive_bytes(size, response);
	if (ret_code == SWI_FUNCTION_RETCODE_SUCCESS || ret_code == SWI_FUNCTION_RETCODE_RX_FAIL) {
		count_byte = response[SHA204_BUFFER_POS_COUNT];
		if ((count_byte < SHA204_RSP_SIZE_MIN) || (count_byte > size))
			return SHA204_INVALID_SIZE;

		return SHA204_SUCCESS;
	}

	// Translate error so that the Communication layer
	// can distinguish between a real error or the
	// device being busy executing a command.
	if (ret_code == SWI_FUNCTION_RETCODE_TIMEOUT)
		return SHA204_RX_NO_RESPONSE;
	else
		return SHA204_RX_FAIL;
}


/** \brief This SWI function generates a Wake-up pulse and delays.
 * \return success
*/
uint8_t sha204p_wakeup(void)
{
	swi_set_signal_pin(0);
	sha204h_delay_us(60); 
	swi_set_signal_pin(1);
	sha204h_delay_ms(SHA204_WAKEUP_DELAY);
	return SHA204_SUCCESS;
}


/** \brief This SWI function puts the device into idle state.
 * \return status of the operation
 */
uint8_t sha204p_idle()
{
	return swi_send_byte(SHA204_SWI_FLAG_IDLE);
}


/** \brief This SWI function puts the device into low-power state.
 *  \return status of the operation
 */
uint8_t sha204p_sleep() {
	return swi_send_byte(SHA204_SWI_FLAG_SLEEP);
}


/** \brief This SWI function is only a dummy since the
 *         functionality does not exist for the SWI
 *         version of the SHA204 device.
 * \return success
 */
uint8_t sha204p_reset_io(void)
{
	return SHA204_SUCCESS;
}


/** \brief This function re-synchronizes communication.
 *
  Re-sychronizing communication is done in a maximum of five
  steps listed below. This function implements the first three steps.
  Since steps 4 and 5 (sending a Wake-up token and reading the
  response) are the same for TWI and SWI, they are implemented
  in the communication layer (#sha204c_resync).\n
  If the chip is not busy when the system sends a transmit flag,
  the chip should respond within t_turnaround. If t_exec has not
  already passed, the chip may be busy and the system should poll or
  wait until the maximum tEXEC time has elapsed. If the chip still
  does not respond to a second transmit flag within t_turnaround,
  it may be out of synchronization. At this point the system may
  take the following steps to reestablish communication:
  <ol>
     <li>Wait t_timeout.</li>
     <li>Send the transmit flag.</li>
     <li>
       If the chip responds within t_turnaround,
       then the system may proceed with more commands.
     </li>
     <li>Send a Wake token, wait t_whi, and send the transmit flag.</li>
     <li>
       The chip should respond with a 0x11 return status within
       t_turnaround, after which the system may proceed with more commands.
     </li>
   </ol>

 * \param[in] size size of rx buffer
 * \param[out] response pointer to response buffer
 * \return status of the operation
 */
uint8_t sha204p_resync(uint8_t size, uint8_t *response)
{
	sha204h_delay_ms(85);
	return sha204p_receive_response(size, response);
}
