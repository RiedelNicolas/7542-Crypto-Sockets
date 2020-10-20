//
// Created by riedel on 17/10/20.
//

#include "common_Encrypter.h"
#include <stdlib.h>  // for ATOI
#define SUCCESS 0
#define FAILURE -1
#define ENCRYPT_MODE  1
#define DECRYPT_MODE  -1

// Privadas

void _encrypterCesar(Encrypter* this, char* msg, size_t size, int mode);
void _encrypterRC4(Encrypter* this, char* msg, size_t size,  int mode);
void _encrypterVignere(Encrypter* this, char* msg, size_t size, int mode);
void _encrypterRC4GenerateSemiRandom(struct Encrypter* this);

// publicas
int encrypterInit(Encrypter* this, char* method, char* key) {
    this->key = key;
    this->cursor = 0;

    if ( !strcmp(method, CESAR) ) {
        this->function  = _encrypterCesar;
        return SUCCESS;
    }
    if ( !strcmp(method, RC4) ) {
        this->function = _encrypterRC4;
        _encrypterRC4GenerateSemiRandom(this);
        return SUCCESS;
    }
    if ( !strcmp(method, VIGNERE) ) {
        this->function =  _encrypterVignere;
        return SUCCESS;
    }
    fprintf(stderr, "unknow encryption method \n");
    return FAILURE;
}

void encrypterEncrypt(Encrypter* this, char* msg, size_t size) {
    this->function(this, msg, size, ENCRYPT_MODE);
}

void encrypterDecrypt(Encrypter* this, char* msg, size_t size) {
    this->function(this, msg, size, DECRYPT_MODE);
}

void encrypterReset(Encrypter* this) {
    this->cursor = 0;
}

void encrypterUninit(Encrypter* this) {
    encrypterReset(this);
}



void _encrypterCesar(Encrypter* this, char* msg, size_t size, int mode) {
    int key = atoi(this->key);
    for (size_t i = 0; i < size ; i++) {
        msg[i] += (char) ( (key*mode) );
    }
}

void _encrypterRC4GenerateSemiRandom(struct Encrypter* this) {
    int len = strlen(this->key);
    int i, j = 0;
    for ( i = 0; i < SEMI_RANDOM_SIZE ; ++i ) {
        (this->semiRandom)[i] = i;
    }
    for (i = 0; i < SEMI_RANDOM_SIZE ; ++i) {
        j = ((j+ (this->semiRandom)[i] + (this->key)[i%len] ) %256);
        unsigned char temp = (this->semiRandom)[i];
        (this->semiRandom)[i] = (this->semiRandom)[j];
        (this->semiRandom)[j] = temp;
    }
}


void _encrypterRC4(Encrypter* this, char* msg, size_t size, int mode) {
    // ya tenemos generado el semirandom.
    size_t j = 0;
    unsigned char* random = this->semiRandom;
    for (size_t i = 0; i < size ; ++i) {
        i = (i+1)%SEMI_RANDOM_SIZE;
        j = (j + random[i]) %SEMI_RANDOM_SIZE;
        char temp = (random)[i];
        (random)[i] = (random)[j];
        (random)[j] = temp;
        char round = random[random[i] + random[j] %SEMI_RANDOM_SIZE];
        msg[i] = (round ^ msg[i]);
    }
}


void _encrypterVignere(Encrypter* this, char* msg, size_t size, int mode) {
    char* key = this->key;

    for (size_t i = 0; i < size ; i++) {
        msg[i] +=  (key[ ( (this->cursor)%strlen(key) ) ]*mode);
        (this->cursor)++;
    }
}
