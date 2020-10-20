//
// Created by riedel on 13/10/20.
//


#include "common_Parser.h"
#include "client_Courier.h"

#define SIZE_BUFFER 64

int main(int argc, char** argv) {
    char buffer[SIZE_BUFFER];
    Courier courier;
    Parser parser;

    parserInit(&parser, CLIENT_MODE);
    parserParse(&parser, argv, argc);


    courierInit(&courier, parser.method, parser.key, parser.host, parser.port);
    courierRun(&courier, buffer, SIZE_BUFFER);

    courierUninit(&courier);
    parserUninit(&parser);
    return 0;
}
