//
// Created by riedel on 13/10/20.
//

#ifndef SERVER_H_
#define SERVER_H_
#include "common_Socket.h"

typedef struct {
    Socket socket;
    Socket peer;
}Server;

/*
 * Constructor
 */
void serverInit(Server* this);
/*
 * Bind to a port and waiting for a peer to connect.
 * FAILURE on error, displays on stderr.
 */
int serverBindAndListen(Server*  this, const char* port, int max_listen);
/*
 * Accepts one of the waiting list. If the list is empty its a BLOCKING
 * FUNCTION,
 */
void serverAcceptOne(Server* this);
/*
 * Receives from peer, returns the number of bytes successfully received
 * -1 on error.
 *
 */
ssize_t serverRecv(Server* this, char* buffer, size_t len);
/*
 * Destructor
 */
void serverUninit(Server* this);

#endif  // SERVER_H_

