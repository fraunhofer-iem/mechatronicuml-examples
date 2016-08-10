/**
 * @file 
 * @author generated
 * @brief The typedefs for the  Messages are definied here
 * @details To guarantee unique Names for Messages, the Name of the corresponding MessageTypeReposity is appended
 */
#ifndef MESSAGE_TYPES_H
#define MESSAGE_TYPES_H
#include "../lib/standardTypes.h"


//the following message types are not generated, because they have no parameters

//definition for message type MessagesDoneOrder
typedef struct MessagesDoneOrder_Messages_Message{
	 int32_T orderID;
}MessagesDoneOrder_Messages_Message;
//definition for message type MessagesOrderForPS
typedef struct MessagesOrderForPS_Messages_Message{
	 int32_T receiverPsID;
	 int32_T orderID;
	 int32_T incredientID;
	 int32_T amount;
}MessagesOrderForPS_Messages_Message;
//definition for message type MessagesNoOrder
typedef struct MessagesNoOrder_Messages_Message{
	 int32_T receiverPsID;
}MessagesNoOrder_Messages_Message;
//definition for message type MessagesGetOrder
typedef struct MessagesGetOrder_Messages_Message{
	 int32_T psID;
}MessagesGetOrder_Messages_Message;
//definition for message type MessagesSimpleOrder
typedef struct MessagesSimpleOrder_Messages_Message{
	 int32_T orderID;
	 int32_T ingredientID;
	 int32_T amount;
}MessagesSimpleOrder_Messages_Message;
#endif /* MESSAGE_TYPES_H */