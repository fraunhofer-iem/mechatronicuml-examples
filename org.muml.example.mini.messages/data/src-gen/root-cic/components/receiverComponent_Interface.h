	/**
 * @file 
 * @author generated by Fraunhofer IEM
 * @brief Specification of Component of Type: Receiver
 * @details This files contains a description of the Receiver in form of the ReceiverComponent
 * 			and all methods which can be executed on an Instance of this Component
 */
		#ifndef RECEIVERCOMPONENT_INTERFACE_H_
		#define RECEIVERCOMPONENT_INTERFACE_H_

#ifdef __cplusplus
  extern "C" {
#endif
				// Library
				#include "../types/standardTypes.h"
				#include "../types/customTypes.h"
					#include "../lib/port.h"
					#include "../messages/Messages.h"
			
					#include "../continuousComponents/contImplementations.h"	
					
					
				
			
				#include "../lib/clock.h"
			#include "../lib/Debug.h"
			#include "../lib/MiddlewareTypes.h"
			#include "../Middleware/MiddlewareCore.h"
				
			
	
			/**
			 * @brief Forward Declaration of the struct ReceiverReceiverStateChart which describes the behavior of ReceiverComponent
			 * 
			 */
			 typedef struct ReceiverReceiverStateChart ReceiverReceiverStateChart;
			/**
			 * @brief Forward Declaration of the struct ReceiverComponent
			 */
				typedef struct ReceiverComponent ReceiverComponent;
			
			/**
			*  
			* @brief Description for a ComponentInstance of Type: Receiver
			* @details This struct describes a specific Component Instances which is typed over the Component: Receiver
			*/
			struct ReceiverComponent {
			
			
						ReceiverReceiverStateChart* stateChart;	/**< The ReceiverReceiverStateChart of the Component Receiver */
				
							Port* inPort; /**< A Pointer to the Component's Port: in */
			
								void (*setterOf_LED)(int8_T);/**< A Pointer to the setter function of the hybrid port: LED */
			
						
					
					
			
					ReceiverComponent * next;/**< A Pointer to the next component part, if this component ist part of a multipart in the CIC */
					
				};
		
			/**
			* @brief This Methodes intializes the Component: Receiver
			* @details All struct members of the struct ReceiverComponent are initialized
			* 
			* @param component The ReceiverComponent to be initialized
			*/	
				void ReceiverComponent_initialize(ReceiverComponent* component);
	
			/**
			* @brief Creates a Instance of the Component: Receiver
			* @details Allocates Memory for the struct ReceiverComponent
			* @return A Pointer to the new created ReceiverComponent
			*/
				ReceiverComponent* ReceiverComponent_create();
	
			/**
			 * @brief Destroys a Component: Receiver
			 * @details Frees the Memory for the struct ReceiverComponent
			 * 
			* @param component The specific ReceiverComponent to be destroyed
			 */
				void ReceiverComponent_destroy(ReceiverComponent* component);
		
			
			/**
			* @brief Executes the next Step of the behavior an Instance of the Component: Receiver
			* @details The behavior of the Component:  Receiver is executed.
			*			
			* @param component The ReceiverComponent whose behavior shall be checked
			*/
				void ReceiverComponent_processStep(ReceiverComponent* component);
		
			/**
					 * @brief Get the Port: in of an Instance of the Component: Receiver
					 * @details The Pointer ReceiverComponent::inPort is returned
					 * 
					 * @param component The specific Instance ReceiverComponent  of the Component: Receiver whose Port shall be returned
					 * @return A Pointer to the Port in of the struct ReceiverComponent
					 */
					Port* ReceiverComponent_getin(ReceiverComponent* component);
		
			

		
/**
 * @file 
 * @author generated by Fraunhofer IEM
 * @brief Specification of Realtime-StateChart: ReceiverReceiver
 * @details This files contains the description of the Realtime-StateChart: ReceiverReceiver and its behavior which is executed
 */
	//ENUM
	/** 
	 * @brief This enum represents the States of the Realtime-StateChart: ReceiverReceiver
	 */
		typedef enum {
			RECEIVERRECEIVER_INACTIVE,
			STATE_RECEIVERRECEIVER_MAIN /**< Represents the State: STATE_RECEIVERRECEIVER_MAIN of the Realtime-StateChart: ReceiverReceiver */
			,
					STATE_RECEIVERININIT /**< Represents the State: STATE_RECEIVERININIT of the Realtime-StateChart: ReceiverInReceiverRoleRTSC_in */	
		}ReceiverReceiverState;
	
	
		/**
		 * 
		 * @brief Description of the Realtime-StateChart: ReceiverReceiver
		 * @details This struct represents the  Realtime-StateChart: ReceiverReceiver and its States
		 */
	struct ReceiverReceiverStateChart {	
			ReceiverComponent * parentComponent;/**< A pointer to the parent ComponentInstance of Type: ReceiverComponent , which has this Realtime-StateChart as its behavior */			
	
	
						ReceiverReceiverState currentStateOfReceiverReceiver;/**< The current State of the Realtime-StateChart: ReceiverReceiver */
	
				ReceiverReceiverState currentStateOfReceiverInReceiverRoleRTSC_in;/**< Represents the state of region: ReceiverInReceiverRoleRTSC_in */
	
			bool_t ReceiverReceiver_isExecutable;/**< Execution Verifier of RTSC: ReceiverReceiver. This variable is used to ensure that a RTSC is executed only once per execution cycle */
				bool_t ReceiverInReceiverRoleRTSC_in_isExecutable;/**< Execution Verifier of RTSC: ReceiverInReceiverRoleRTSC_in. This variable is used to ensure that a RTSC is executed only once per execution cycle */
		
	
	
		
	
	
					int8_T LED;
	
	
			
	
		} ;

//METHOD STUBS
	/**
	 * @brief Creates an Instance of the Realtime-StateChart: ReceiverReceiver
	 * @details Allocates Memory for the struct ReceiverReceiverStateChart
	 * 
	 * @param parentComponent An Instance of the Component: ReceiverComponent which behavior is described via this Realtime-StateChart
	 * @return A Pointer to the new created ReceiverReceiverStateChart
	 */
		ReceiverReceiverStateChart* ReceiverReceiverStateChart_create(ReceiverComponent* parentComponent);
	/**
	 * @brief Initializes an Instance of the Realtime-StateChart: ReceiverReceiver
	 * @details All struct members of the struct ReceiverReceiverStateChart are initialized,
	 *			and all Regions of the Realtime-StateChart are initialized, too.
	 * 
	 * @param rtsc The specific ReceiverReceiverStateChart to be initialized
	 */
		void ReceiverReceiverStateChart_initialize(ReceiverReceiverStateChart* rtsc);
	/**
	 * @brief Initializes the Region: ReceiverInReceiverRoleRTSC_in of the Realtime-StateChart: ReceiverReceiver
	 * @details The Member ReceiverReceiverStateChart::currentStateOfReceiverInReceiverRoleRTSC_in is initialized
	 * 
	 * @param stateChart The specific ReceiverReceiverStateChart whose Region shall be initialized
	 */
	
		void initializeReceiverInReceiverRoleRTSC_inRegion(ReceiverReceiverStateChart* stateChart);
	/**
	 * @brief Destroys the Realtime-StateChart: ReceiverReceiver
	 * @details Frees the Memory for the struct ReceiverReceiverStateChart
	 * 
	 * @param rtsc The specific ReceiverReceiverStateChart to be destroyed
	 */	
		void ReceiverReceiverStateChart_destroy(ReceiverReceiverStateChart* rtsc);		
	/**
	 * @brief Executes the next Step of the Realtime-StateChart: ReceiverReceiver
	 * 
	 * @param rtsc The specific ReceiverReceiverStateChart to be executed
	 */	
		void ReceiverReceiverStateChart_processStep(ReceiverReceiverStateChart* rtsc);

	/**
	 * @brief Leaves the Region: receiverRoleRTSC_in of the Realtime-StateChart: ReceiverReceiver
	 * @details This method is called, whenever a the Region: receiverRoleRTSC_in is left.
	 * 			The correct State is set and all Exit-Events are executed.
	 *
	 * @param rtsc The specific ReceiverReceiverStateChart whose Region: receiverRoleRTSC_in shall be exit
	 */
		void ReceiverInReceiverRoleRTSC_inStateChart_exit(ReceiverReceiverStateChart* rtsc);
			
	/**
	 * @brief Returns wether the Realtime-StateChart: ReceiverReceiver is in a specific State
	 * 
	 * @param rtsc The specific Realtime-StateChart: ReceiverReceiverStateChart
	 * @param state One of the States of the Enum: ReceiverReceiverState
	 * 
	 * @return True, If the Realtime-StateChart is in the specific State, otherwise False
	 */	
		bool_t ReceiverReceiverStateChart_isInState(ReceiverReceiverStateChart* rtsc, ReceiverReceiverState state);
	

//RTSC internal operations









#ifdef __cplusplus
  }
#endif
		#endif /* RECEIVERCOMPONENT_INTERFACE_H_ */


