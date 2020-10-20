//
// Created by riedel on 13/10/20.
//

#ifndef CLIENT_H_
#define CLIENT_H_

#include "common_Socket.h"

typedef struct {
    Socket socket;
}Client;
/*
 * Constructor
 */
void clientInit(Client* this);
/*
 * Connects to a waiting server.
  * Returns FAILURE on fail, specifies error on stderr.
 */
int clientConnect(Client*  this, const char* host, const char* port);
/*
 * Sends data to Server on the other end, returns how many bytes were sent.
 * -1 on failure. specifies error on stderr.
 */
ssize_t clientSend(Client* this, const char* buffer, size_t len);
/*
 * Destructor
 */
void clientUninit(Client* this);

#endif  // CLIENT_H_
