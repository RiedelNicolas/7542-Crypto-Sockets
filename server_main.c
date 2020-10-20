//
// Created by riedel on 13/10/20.
//



#include  "server_Receiver.h"
#include "common_Parser.h"

#define SIZE_BUFFER 64

int main(int argc, char** argv) {
    char buffer[SIZE_BUFFER];
    Receiver receiver;
    Parser parser;


    parserInit(&parser, SERVER_MODE);
    parserParse(&parser, argv, argc);

    receiverInit(&receiver, parser.method, parser.key, parser.port);
    receiverRun(&receiver, buffer, SIZE_BUFFER);
    receiverUninit(&receiver);
    return 0;
}
