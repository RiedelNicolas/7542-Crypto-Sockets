//
// Created by riedel on 13/10/20.
//


#include <stdio.h>
#include <getopt.h>
#include  "server_Receiver.h"

#define POS_PORT 1

#define SIZE_BUFFER 64

int main(int argc, char** argv) {
    int opt = 0;
    int long_index = 0;
    char* method = NULL, *key = NULL;

    char* port  = argv[POS_PORT];

    static struct option long_options[] = {
            {"method", required_argument, NULL, 'm'},
            {"key",    required_argument, NULL, 'k'},
            {NULL, 0,                     NULL, 0}
    };
    while ((opt = getopt_long(argc, argv, ":m:k:",
                              long_options, &long_index)) != -1) {
        switch (opt) {
            case 'm' : method = optarg;
                break;
            case 'k' : key = optarg;
                break;
        }
    }

    char buffer[SIZE_BUFFER];
    Receiver receiver;

    receiverInit(&receiver, method, key, port);
    receiverRun(&receiver, buffer, SIZE_BUFFER);
    receiverUninit(&receiver);
}
