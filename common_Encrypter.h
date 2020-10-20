//
// Created by riedel on 17/10/20.
//

#ifndef COMMON_ENCRYPTER_H_
#define COMMON_ENCRYPTER_H_

#include <stdio.h>
#include <string.h>

#define CESAR "cesar"
#define RC4 "rc4"
#define VIGENERE "vigenere"
#define ASCII_SIZE 256

typedef struct Encrypter {
    size_t cursor;  // para acordarme en que numero de iteracion estoy.
    char* key;
    void (*function)(struct Encrypter*, char*, size_t, int);
    unsigned char r[ASCII_SIZE];
    unsigned int j;
    unsigned int i;
}Encrypter;


int encrypterInit(Encrypter* this, char* method, char* key);
void encrypterEncrypt(Encrypter* this, char* msg, size_t size);
void encrypterDecrypt(Encrypter* this, char* msg, size_t size);
void encrypterReset(Encrypter* this);
void encrypterUninit(Encrypter* this);


#endif  // COMMON_ENCRYPTER_H_
