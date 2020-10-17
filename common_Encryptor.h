//
// Created by riedel on 17/10/20.
//

#ifndef CLIONPROJECTS_COMMON_ENCRYPTOR_H
#define CLIONPROJECTS_COMMON_ENCRYPTOR_H

#include <stdio.h>
#include <string.h>

#define CESAR "cesar"
#define RC4 "rc4"
#define VIGNERE "vignere"

typedef struct Encryptor{
    size_t cursor; //para acordarme en que numero de iteracion estoy.
    char* key;
    void (*encryptFunction)(struct Encryptor*, char*, size_t);
    void (*decryptFunction)(struct Encryptor*, char*, size_t);
}Encryptor;


void encryptorInit(Encryptor* this, char* method, char* key );
void encryptorEncrypt(Encryptor* this,char* msg, size_t size);
void encryptadorDecrpyt(Encryptor* this,char* msg, size_t size);
void encryptorReset(Encryptor* this);
void encrpytorUninit(Encryptor* this);


#endif //CLIONPROJECTS_COMMON_ENCRYPTOR_H
