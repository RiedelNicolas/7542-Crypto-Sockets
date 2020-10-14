//
// Created by riedel on 12/10/20.
//

#include "common_Socket.h"
#define FAILURE -1
#define SUCCESS 0
#define INVALID_FD -1
#define CLIENT_MODE 'C'
#define SERVER_MODE 'S'

//ojo que esta no hace free

static int _getaddrinfo(struct addrinfo** result, const char mode,const char* host, const char* port ){
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints) );memset(&hints, 0, sizeof(hints) );
    hints.ai_flags = AI_PASSIVE;
    hints.ai_family =AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if(mode == SERVER_MODE) hints.ai_flags = AI_PASSIVE;
    int error = getaddrinfo(host,port,&hints,result);
    if(error !=0 ){
        fprintf(stderr,"error en getaddrinfo:%s\n",gai_strerror(error));
        return FAILURE;
    }
    return SUCCESS;
}

void socketInit(Socket* this){
    this->fd = INVALID_FD;
}
void socketUninit(Socket* this){
    if(this->fd !=INVALID_FD){
        shutdown(this->fd,SHUT_RDWR);
        close(this->fd);
    }
}


int socketConnect(Socket* this, const char* host, const char* port ){
    struct addrinfo  *result, *current;
    int error;

    error = _getaddrinfo(&result,CLIENT_MODE,host,port);
    if(error != 0) return FAILURE;

    for (current = result; current !=NULL ; current = current->ai_next) {
        this->fd = socket(current->ai_family,current->ai_socktype,current->ai_protocol);
        if(this->fd==INVALID_FD) {
            continue;
        }
        if(connect(this->fd,current->ai_addr,current->ai_addrlen)!=-1){
            break; //success
        }
        if (this->fd != INVALID_FD  ) close(this->fd);
    }
    freeaddrinfo(result);
    if (this->fd == INVALID_FD ){
        fprintf(stderr,"Unable to connect\n");
        return FAILURE;
    }
    return SUCCESS;
}
//hablando con eze llegamos a que send no puede mandar 0
ssize_t socketSend(Socket* this, const char* buffer, size_t len){
    ssize_t sent = 0,current = 0;

    while (sent<len ){
        current = send(this->fd,&buffer[sent],len-sent,MSG_NOSIGNAL);
        if(current == -1 ){
            fprintf(stderr,"unable to send data\n %s", strerror(errno) );
            return FAILURE;
        }
        sent+=current;
    }
    return sent;
}

ssize_t socketRecv(Socket* this, char* buffer, size_t len){
    ssize_t received = 0, current = 0;
    while (received < len ){
        current = recv(this->fd,&buffer[received],len - received, 0);
        if (current == -1){
            fprintf(stderr,"unable to recv data\n %s", strerror(errno) ) ;
            return FAILURE;
        }
        if(current == 0 )break;
        received+=current;
    }
    return received;
}

int socketBindAndListen(Socket* this, const char* port, int maxListen){

    struct addrinfo *result, *current;

    int error = _getaddrinfo(&result,SERVER_MODE,NULL,port );
    if(error!=0) return FAILURE;

    for ( current = result; current!=NULL; current=current->ai_next ){
        this->fd = socket(current->ai_family,current->ai_socktype,current->ai_protocol);
        if (this->fd == -1) continue;
        int val = 1;
        setsockopt(this->fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
        if(bind(this->fd,current->ai_addr,current->ai_addrlen) == 0 ) break; //success
        close(this->fd);
    }
    freeaddrinfo(result); //already used
    if(current == NULL){
        fprintf(stderr, "couldnt bind \n");
        return FAILURE;
    }

    freeaddrinfo(result);
    listen(this->fd,maxListen);
    return SUCCESS;
}

/*
 acepta un cliente, supongo socket correctamente inciado */
void socketAcceptOne(Socket* this, Socket* peer){
    peer->fd = accept(this->fd,NULL,NULL);
    if(peer->fd  == -1){
        fprintf(stderr,"unable to receive peer\n %s", strerror(errno) );
    }
}
