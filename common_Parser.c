//
// Created by riedel on 20/10/20.
//

#include "common_Parser.h"
#include <stdio.h>
#define  FAILURE -1
#define SUCCESS 0

#define CLIENT_POS_HOST 1
#define CLIENT_POS_PORT 2
#define CLIENT_ARGS 5
#define SERVER_POS_PORT 1
#define SERVER_ARGS 4

void parserInit(Parser* this, char mode) {
    this->mode = mode;
    this->host = NULL;
    this->port = NULL;
    this->key  = NULL;
    this->method = NULL;
}

int _parserParseClient(Parser* this, char** argv, int argc,
                       struct option long_options[]) {
    int opt = 0, long_index = 0;
    this->host = argv[CLIENT_POS_HOST];
    this->port = argv[CLIENT_POS_PORT];
    while ((opt = getopt_long(argc, argv, ":m:k:",
                              long_options, &long_index)) != -1) {
        switch (opt) {
            case 'm' : this->method = optarg;
                break;
            case 'k' : this->key = optarg;
                break;
        }
    }
    if (argc != CLIENT_ARGS ||
        this->method == NULL || this->key == NULL) {
        fprintf(stderr, "wrong arguments \n");
        return FAILURE;
    }
    return SUCCESS;
}

int _parserParseServer(Parser* this, char** argv, int argc,
                       struct option long_options[] ) {
    int opt = 0, long_index = 0;
    this->port = argv[SERVER_POS_PORT];
    while ((opt = getopt_long(argc, argv, ":m:k:",
                              long_options, &long_index)) != -1) {
        switch (opt) {
            case 'm' : this->method = optarg;
                break;
            case 'k' : this->key = optarg;
                break;
        }
    }

    if (argc != SERVER_ARGS ||
        this->method == NULL || this->key == NULL) {
        fprintf(stderr, "wrong arguments \n");
        return FAILURE;
    }
    return SUCCESS;
}

int parserParse(Parser* this, char** argv, int argc) {
    static struct option long_options[] = {
            {"method", required_argument, NULL, 'm'},
            {"key",    required_argument, NULL, 'k'},
            {NULL, 0,                     NULL, 0}
    };

    if (this->mode == SERVER_MODE) {
        return _parserParseServer(this, argv, argc, long_options);
    }
    if (this->mode == CLIENT_MODE) {
        return _parserParseClient(this, argv, argc, long_options);
    }
    return FAILURE;
}

void parserUninit(Parser* this) {
    this->host = NULL;
    this->port = NULL;
    this->key  = NULL;
    this->method = NULL;
}
