#include "MiddlewareInternalLogic.h"


/*
 * determines the targetECU
 * uses ECU-table, based on the allocation-model
 * For now, only a switch-case statement. Later this should be implemented
 * in some hash-table to allow changes during runtime.
 */
ECUID MW_getTargetECU(PortID targetPort) {
	switch(targetPort){

		case PORT_PICKUPBOTINSTANCEPICKUPBOTPICKUPBOTPORTINSTANCE:
		return ECU_RASPBERRYPI01;
		break;
		case PORT_MOTORLEFTMOTORMOTORPORT:
		return ECU_invalid;
		break;
		case PORT_MOTORRIGHTMOTORMOTORPORT:
		return ECU_invalid;
		break;
		case PORT_DRIVERDRIVERDRIVERPORT1:
		return ECU_BRICK101;
		break;
		case PORT_DRIVERDRIVERLINELEADERPORT:
		return ECU_BRICK101;
		break;
		case PORT_DRIVERDRIVERMOTORLEFTPORT:
		return ECU_BRICK101;
		break;
		case PORT_DRIVERDRIVERMOTORRIGHTPORT:
		return ECU_BRICK101;
		break;
		case PORT_LINELEADERLINELEADERSENSORLINELEADERPORT:
		return ECU_invalid;
		break;
		case PORT_MAINCONTROLLERMAINCONTROLLERLOADINGCONTROLLERPORT1:
		return ECU_BRICK101;
		break;
		case PORT_MAINCONTROLLERMAINCONTROLLERDRIVINGCONTROLLERPORT1:
		return ECU_BRICK101;
		break;
		case PORT_MAINCONTROLLERMAINCONTROLLERPICKINGUPCONTROLLERPORT1:
		return ECU_BRICK101;
		break;
		case PORT_MAINCONTROLLERMAINCONTROLLERCOLORPORT:
		return ECU_BRICK101;
		break;
		case PORT_COLORCOLORSENSORCOLORPORT:
		return ECU_invalid;
		break;
		case PORT_COMMUNICATORCOMMUNICATORCOMMUNICATORPORT1:
		return ECU_BRICK201;
		break;
		case PORT_COMMUNICATORCOMMUNICATORPICKUPPORT1:
		return ECU_BRICK201;
		break;
		case PORT_LOADCONTROLLERLOADCONTROLLERLOADERPORT1:
		return ECU_BRICK201;
		break;
		case PORT_LOADCONTROLLERLOADCONTROLLERTOUCHPORT:
		return ECU_BRICK201;
		break;
		case PORT_TOUCHTOUCHSENSORTOUCHPORT:
		return ECU_invalid;
		break;
		default:
			return -1;
		}
}

/*
 * determines the targetECU for network communication
 * uses ECU-table, based on the PDM
 */
ECUID MW_getNextStepECU(ECUID ecu)
{
   switch (ecu) {
case ECU_BRICK101:
	return ECU_BRICK101;
	break;
case ECU_BRICK201:
	return ECU_BRICK201;
	break;
case ECU_RASPBERRYPI01:
	return -1;
	break;
        default:
            return -1;
    }
}

/*
 * returns a network interface which is able to contact the NextStep-ECU
 * uses NI-table, based on PDM
 */
NetworkInterface* MW_getNetworkInterface(ECUID ecu)
{
	switch (ecu)
	{
case ECU_BRICK101:
	return mw->intern;
	break;
case ECU_BRICK201:
	return mw->inputPort4;
	break;
case ECU_RASPBERRYPI01:
	return NULL;
	break;
        default: return NULL; 
	}
}

Port* MW_getPortforIdentifier(PortID portID){
    switch (portID) {
case PORT_DRIVERDRIVERDRIVERPORT1:
	return mw->driverComponent->driverPortPort;
	break;
case PORT_DRIVERDRIVERLINELEADERPORT:
	return mw->driverComponent->lineLeaderPortPort;
	break;
case PORT_DRIVERDRIVERMOTORLEFTPORT:
	return mw->driverComponent->motorLeftPortPort;
	break;
case PORT_DRIVERDRIVERMOTORRIGHTPORT:
	return mw->driverComponent->motorRightPortPort;
	break;
case PORT_MAINCONTROLLERMAINCONTROLLERLOADINGCONTROLLERPORT1:
	return mw->mainControllerComponent->loadingControllerPortPort;
	break;
case PORT_MAINCONTROLLERMAINCONTROLLERDRIVINGCONTROLLERPORT1:
	return mw->mainControllerComponent->drivingControllerPortPort;
	break;
case PORT_MAINCONTROLLERMAINCONTROLLERPICKINGUPCONTROLLERPORT1:
	return mw->mainControllerComponent->pickingUpControllerPortPort;
	break;
case PORT_MAINCONTROLLERMAINCONTROLLERCOLORPORT:
	return mw->mainControllerComponent->colorPortPort;
	break;
        default:
            return NULL;
    }
    
}


/*
* Return the  PortID of a receiving port for a given sender PortID
*
*/
PortID MW_getTargetPortIDforIdentifier(PortID portID){ 
switch (portID) {
		case PORT_PICKUPBOTINSTANCEPICKUPBOTPICKUPBOTPORTINSTANCE:
		return PORT_COMMUNICATORCOMMUNICATORCOMMUNICATORPORT1;
		break;
		case PORT_MOTORLEFTMOTORMOTORPORT:
		return PORT_DRIVERDRIVERMOTORLEFTPORT;
		break;
		case PORT_MOTORRIGHTMOTORMOTORPORT:
		return PORT_DRIVERDRIVERMOTORRIGHTPORT;
		break;
		case PORT_DRIVERDRIVERDRIVERPORT1:
		return PORT_MAINCONTROLLERMAINCONTROLLERDRIVINGCONTROLLERPORT1;
		break;
		case PORT_DRIVERDRIVERLINELEADERPORT:
		return PORT_LINELEADERLINELEADERSENSORLINELEADERPORT;
		break;
		case PORT_DRIVERDRIVERMOTORLEFTPORT:
		return PORT_MOTORLEFTMOTORMOTORPORT;
		break;
		case PORT_DRIVERDRIVERMOTORRIGHTPORT:
		return PORT_MOTORRIGHTMOTORMOTORPORT;
		break;
		case PORT_LINELEADERLINELEADERSENSORLINELEADERPORT:
		return PORT_DRIVERDRIVERLINELEADERPORT;
		break;
		case PORT_MAINCONTROLLERMAINCONTROLLERLOADINGCONTROLLERPORT1:
		return PORT_LOADCONTROLLERLOADCONTROLLERLOADERPORT1;
		break;
		case PORT_MAINCONTROLLERMAINCONTROLLERDRIVINGCONTROLLERPORT1:
		return PORT_DRIVERDRIVERDRIVERPORT1;
		break;
		case PORT_MAINCONTROLLERMAINCONTROLLERPICKINGUPCONTROLLERPORT1:
		return PORT_COMMUNICATORCOMMUNICATORPICKUPPORT1;
		break;
		case PORT_MAINCONTROLLERMAINCONTROLLERCOLORPORT:
		return PORT_COLORCOLORSENSORCOLORPORT;
		break;
		case PORT_COLORCOLORSENSORCOLORPORT:
		return PORT_MAINCONTROLLERMAINCONTROLLERCOLORPORT;
		break;
		case PORT_COMMUNICATORCOMMUNICATORCOMMUNICATORPORT1:
		return PORT_PICKUPBOTINSTANCEPICKUPBOTPICKUPBOTPORTINSTANCE;
		break;
		case PORT_COMMUNICATORCOMMUNICATORPICKUPPORT1:
		return PORT_MAINCONTROLLERMAINCONTROLLERPICKINGUPCONTROLLERPORT1;
		break;
		case PORT_LOADCONTROLLERLOADCONTROLLERLOADERPORT1:
		return PORT_MAINCONTROLLERMAINCONTROLLERLOADINGCONTROLLERPORT1;
		break;
		case PORT_LOADCONTROLLERLOADCONTROLLERTOUCHPORT:
		return PORT_TOUCHTOUCHSENSORTOUCHPORT;
		break;
		case PORT_TOUCHTOUCHSENSORTOUCHPORT:
		return PORT_LOADCONTROLLERLOADCONTROLLERTOUCHPORT;
		break;
        default:
            return -1;
    }
}
