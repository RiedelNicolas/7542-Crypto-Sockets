//
// Created by riedel on 17/10/20.
//

#include "common_Encrypter.h"
#include <stdlib.h>  // for ATOI
#define SUCCESS 0
#define FAILURE -1
#define ENCRYPT_MODE  1
#define DECRYPT_MODE  -1

// private

void _encrypterCesar(Encrypter* this, char* msg, size_t size, int mode);
void _encrypterRC4(Encrypter* this, char* msg, size_t size,  int mode);
void _encrypterVigenere(Encrypter* this, char* msg, size_t size, int mode);
void _encrypterRC4GenerateSemiRandom(struct Encrypter* this);


int encrypterInit(Encrypter* this, char* method, char* key) {
    this->key = key;
    this->cursor = 0;
    this->j = 0;
    this->i = 0;

    if ( !strcmp(method, CESAR) ) {
        this->function  = _encrypterCesar;
        return SUCCESS;
    }
    if ( !strcmp(method, RC4) ) {
        this->function = _encrypterRC4;
        _encrypterRC4GenerateSemiRandom(this);
        return SUCCESS;
    }
    if ( !strcmp(method, VIGENERE) ) {
        this->function =  _encrypterVigenere;
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
    this->j = 0;
    this->i = 0;
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
void _encrypterRC4Swap(struct Encrypter* this) {
    unsigned char aux;
    aux = this->r[this->i];
    this->r[this->i] = this->r[this->j];
    this->r[this->j] = aux;
}

void _encrypterRC4GenerateSemiRandom(struct Encrypter* this) {
    this->i = 0;
    this->j = 0;
    size_t len = strlen(this->key);
    for (this->i = 0; this->i < ASCII_SIZE; (this->i)++) {
        this->r[this->i] = this->i;
    }
    for (this->i = 0; this->i < ASCII_SIZE; (this->i)++) {
        this->j = (this->j + this->key[(this->i)%len]
                + this->r[this->i])% ASCII_SIZE;
        _encrypterRC4Swap(this);
    }
    this->i = 0;
    this->j = 0;
}

unsigned char _encrypterRC4GenerateOutPut(struct Encrypter* this) {
    this->i = ((this->i) +1)%ASCII_SIZE;
    this->j = ((this->j)+this->r[this->i])%ASCII_SIZE;
    _encrypterRC4Swap(this);
    return (this->r[(this->r[this->i] + this->r[this->j] )%ASCII_SIZE]);
}


void _encrypterRC4(Encrypter* this, char* msg, size_t size, int mode) {
    for (size_t i = 0; i < size ; i++) {
        msg[i] = (msg[i] ^ _encrypterRC4GenerateOutPut(this) );
    }
}


void _encrypterVigenere(Encrypter* this, char* msg, size_t size, int mode) {
    char* key = this->key;

    for (size_t i = 0; i < size ; i++) {
        msg[i] +=  (key[ ( (this->cursor)%strlen(key) ) ]*mode);
        (this->cursor)++;
    }
}
