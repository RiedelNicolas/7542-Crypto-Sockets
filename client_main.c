//
// Created by riedel on 13/10/20.
//


#include "client_Courier.h"
#define SIZE_BUFFER 64

int main(int argc, char** argv){
    char buffer[SIZE_BUFFER];
    Courier courier;
    char host[80];
    strcpy(host,"localhost");
    courierInit(&courier,argv[2],argv[3],host,argv[1]);
    courierRun(&courier,buffer,SIZE_BUFFER);
    courierUninit(&courier);
}
