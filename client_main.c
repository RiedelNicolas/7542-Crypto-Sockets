//
// Created by riedel on 13/10/20.
//


#include "common_Parser.h"
#include "client_Courier.h"
#define SUCCESS 0
#define FAILURE -1

#define SIZE_BUFFER 64

int main(int argc, char** argv) {
    char buffer[SIZE_BUFFER];
    Courier courier;
    Parser parser;

    parserInit(&parser, CLIENT_MODE);

    if (parserParse(&parser, argv, argc) != SUCCESS) {
        return FAILURE;
    }

    if (courierInit(&courier, parser.method,
                    parser.key, parser.host, parser.port) != SUCCESS) {
        parserUninit(&parser);
        return FAILURE;
    }

    courierRun(&courier, buffer, SIZE_BUFFER);

    courierUninit(&courier);
    parserUninit(&parser);

    return SUCCESS;
}
