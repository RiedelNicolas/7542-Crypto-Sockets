//
// Created by riedel on 17/10/20.
//

#include "common_Encrypter.h"
#include <stdlib.h> //for ATOI
#define SUCCESS 0
#define FAILURE -1

//Privadas

void _encrpyterEncryptCesar(Encrypter* this, char* msg, size_t size);
void _encrypterEncryptRC4(Encrypter* this, char* msg, size_t size);
void _encrypterEncryptVignere(Encrypter* this, char* msg, size_t size);

void _encrpyterDecryptCesar(Encrypter* this, char* msg, size_t size);
void _encrypterDecryptRC4(Encrypter* this, char* msg, size_t size);
void _encrypterDecryptVignere(Encrypter* this, char* msg, size_t size);

//publicas
int encrypterInit(Encrypter* this, char* method, char* key ){
    this->key = key;
    this->cursor = 0;

    if( !strcmp(method, CESAR) ){
        (this->encryptFunction)  = & (_encrpyterEncryptCesar);
        this->decryptFunction  = & (_encrpyterDecryptCesar);
        return SUCCESS ;
    }
    if( !strcmp(method, RC4) ){
        this->encryptFunction = &_encrypterEncryptRC4;
        this->decryptFunction  = &_encrypterDecryptRC4;
        return SUCCESS;
    }
    if( !strcmp(method, VIGNERE) ){
        this->encryptFunction =  & _encrypterEncryptVignere;
        this->decryptFunction  = &_encrypterDecryptVignere;
        return SUCCESS;
    }
    fprintf(stderr, "unknow encryption method \n");
    return FAILURE;
}

void encryptorEncrypt(Encrypter* this, char* msg, size_t size){
    this->encryptFunction(this,msg,size);
}

void encrypterDecrypt(Encrypter* this, char* msg, size_t size){
    this->decryptFunction(this,msg,size);
}

void encryptorReset(Encrypter* this){
    this->cursor = 0;
}
void encrpytorUninit(Encrypter* this){
    this->key = NULL;
    this->cursor = 0;
    this->decryptFunction = NULL;
    this->encryptFunction = NULL;
}



void _encrpytorCesar(Encrypter* this, char* msg, size_t size){
    int key = atoi(this->key);
    for (size_t i = 0; i < size ; i++){
        msg[i] = msg[i] + key ;
    }
}

void _encryptorRC4(Encrypter* this, char* msg, size_t size);
void _encryptorVignere(Encrypter* this, char* msg, size_t size);