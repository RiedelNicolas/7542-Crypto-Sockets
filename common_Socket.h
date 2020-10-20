//
// Created by riedel on 12/10/20.
//

#ifndef COMMON_SOCKET_H_
#define COMMON_SOCKET_H_

#define _POSIX_C_SOURCE 201112L  // lo vi en ejemplo de catedra.

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
typedef struct Socket {
    int fd;
}Socket;

/*
 * Constructor
 */
void socketInit(Socket* this);
/*
 * Destructor
 */
void socketUninit(Socket* this);
/*
 * Binds the Socket to the specified port, then listen waiting for peers.
 * BLOCKING FUNCTION.
 * Returns FAILURE or SUCCESS, displays the error on stderror.
 */
int socketBindAndListen(Socket* this, const char* port, int maxListen);
/*
 * Accepts one peer from the list, if its empty its a blocking function,
 * keeps waiting for a peer to connect.
 */
void socketAcceptOne(Socket* this, Socket* peer);
/*
 *  Connects to a listening socket.
 * Returns FAILURE or SUCCESS, displays the error on stderro.
 */
int socketConnect(Socket* this, const char* host, const char* port);
/*
 * Sends a chunk of bytes to the other end.
 * Returns the numbers of bytes sent, -1 on failure.
 */
ssize_t socketSend(Socket* this, const char* buffer, size_t len);
/*
 * Receives a chunk of bytes,
 * the return value represent the number of bytes that were possible
 * to read. -1 on failure.
*/
ssize_t socketRecv(Socket* this, char* buffer, size_t len);

#endif  // COMMON_SOCKET_H_

