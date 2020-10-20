//
// Created by riedel on 17/10/20.
//

#ifndef CLIONPROJECTS_COMMON_ENCRYPTER_H
#define CLIONPROJECTS_COMMON_ENCRYPTER_H

#include <stdio.h>
#include <string.h>

#define CESAR "cesar"
#define RC4 "rc4"
#define VIGNERE "vignere"
#define SEMI_RANDOM_SIZE 256

typedef struct Encrypter{
    size_t cursor; //para acordarme en que numero de iteracion estoy.
    char* key;
    void (*function)(struct Encrypter*, char*, size_t, int);
    unsigned char semiRandom[SEMI_RANDOM_SIZE];
}Encrypter;


int encrypterInit(Encrypter* this, char* method, char* key );
void encrypterEncrypt(Encrypter* this, char* msg, size_t size);
void encrypterDecrypt(Encrypter* this, char* msg, size_t size);
void encrypterReset(Encrypter* this);
void encrypterUninit(Encrypter* this);


#endif //CLIONPROJECTS_COMMON_ENCRYPTER_H
