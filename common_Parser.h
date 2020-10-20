//
// Created by riedel on 20/10/20.
//

#ifndef COMMON_PARSER_H_
#define COMMON_PARSER_H_
#define SERVER_MODE 'm'
#define CLIENT_MODE 'c'
#include <getopt.h>

typedef struct Parser {
    char* host;
    char* port;
    char* method;
    char* key;
    char mode;
}Parser;
/*
 * Constructor, receives the mode CLIENT_MODE or SEVER_MODE.
 */
void parserInit(Parser* this, char mode);
/*
 * GETS the arguments from ARGV.
 * Assigns the pointers host,port,method,key and mode.
 */
int parserParse(Parser* this, char** argv, int argc);
/*
 * Destructor.
 */
void parserUninit(Parser* this);

#endif  // COMMON_PARSER_H_
