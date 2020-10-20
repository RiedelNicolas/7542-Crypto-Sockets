//
// Created by riedel on 13/10/20.
//



#include  "server_Receiver.h"
#include "common_Parser.h"
#define SUCCESS 0
#define FAILURE -1

#define SIZE_BUFFER 64

int main(int argc, char** argv) {
    char buffer[SIZE_BUFFER];
    Receiver receiver;
    Parser parser;

    parserInit(&parser, SERVER_MODE);

    if (parserParse(&parser, argv, argc) != SUCCESS) {
        return FAILURE;
    }

    if (receiverInit(&receiver, parser.method,
                    parser.key, parser.port) != SUCCESS) {
        parserUninit(&parser);
        return FAILURE;
    }

    receiverRun(&receiver, buffer, SIZE_BUFFER);
    receiverUninit(&receiver);
    parserUninit(&parser);
    return SUCCESS;
}
