
RTSC = mainRootRTSCStateChart.o 
COMP = mainComponent.o  
LIB = ContImplementations.o port.o MessageBuffer.o NetworkMessageBuffer.o NetworkInterface.o Messages.o Debug.o
MW = MiddlewareCore.o MiddlewareInternalLogic.o NetworkInterfaceImplementation.o
CC = gcc
CFLAGS = -c
all: app

app : main.o $(RTSC) $(COMP) $(LIB) $(HYB) $(MW)  
	$(CC) main.o $(RTSC) $(COMP) $(LIB) $(HYB) $(MW)  -o app
mainRootRTSCStateChart.o: RTSCs/mainRootRTSCStateChart.c
	$(CC) $(CFLAGS) RTSCs/mainRootRTSCStateChart.c
mainComponent.o: components/mainComponent.c
	$(CC) $(CFLAGS) components/mainComponent.c
ContImplementations.o: continuousComponents/ContImplementations.c
	$(CC) $(CFLAGS) continuousComponents/ContImplementations.c
port.o: lib/port.c
	$(CC) $(CFLAGS) lib/port.c
Debug.o: lib/Debug.c
	$(CC) $(CFLAGS) lib/Debug.c
MessageBuffer.o: lib/MessageBuffer.c
	$(CC) $(CFLAGS) lib/MessageBuffer.c
NetworkMessageBuffer.o: lib/NetworkMessageBuffer.c
	$(CC) $(CFLAGS) lib/NetworkMessageBuffer.c
NetworkInterface.o: lib/NetworkInterface.c
	$(CC) $(CFLAGS) lib/NetworkInterface.c
Messages.o: messages/Messages.c
	$(CC) $(CFLAGS) messages/Messages.c
MiddlewareCore.o: Middleware/MiddlewareCore.c
	$(CC) $(CFLAGS) Middleware/MiddlewareCore.c
MiddlewareInternalLogic.o: Middleware/MiddlewareInternalLogic.c
	$(CC) $(CFLAGS) Middleware/MiddlewareInternalLogic.c
NetworkInterfaceImplementation.o: Middleware/NetworkInterfaceImplementation.c
	$(CC) $(CFLAGS) Middleware/NetworkInterfaceImplementation.c

clean:
	rm -rf *o app
