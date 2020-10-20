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

void parserInit(Parser* this, char mode);
int parserParse(Parser* this, char** argv, int argc);
void parserUninit(Parser* this);

#endif  // COMMON_PARSER_H_
