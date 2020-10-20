//
// Created by riedel on 18/10/20.
//

#ifndef SERVER_RECEIVER_H_
#define SERVER_RECEIVER_H_

#include "server.h"
#include "common_Encrypter.h"
typedef struct Receiver {
    Server server;
    Encrypter  encrypter;
}Receiver;

/*
 * Constructor, receives the port to bind and the method to uncipher the msg.
 */
int receiverInit(Receiver* this, char* method, char* key , char* port);
/*
 * keeps receiving ciphered text.
 * decipher it and displays via standar output.
 * Finish when EOF sygnal is sent.
 */
void receiverRun(Receiver* this, char* buffer, size_t bufferSize);

/*
 * Destructor.
 */
void receiverUninit(Receiver* this);



#endif  // SERVER_RECEIVER_H_
