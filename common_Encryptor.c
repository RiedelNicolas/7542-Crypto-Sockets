//
// Created by riedel on 17/10/20.
//

#include "common_Encryptor.h"
#define SUCCESS 0
#define FAILURE -1

//Privadas

void _encrpytorEncryptCesar(Encryptor* this,char* msg, size_t size);
void _encryptorEncryptRC4(Encryptor* this,char* msg, size_t size);
void _encryptorEncryptVignere(Encryptor* this,char* msg, size_t size);

void _encrpytorDecryptCesar(Encryptor* this,char* msg, size_t size);
void _encryptorDecryptRC4(Encryptor* this,char* msg, size_t size);
void _encryptorDecryptVignere(Encryptor* this,char* msg, size_t size);


int encryptorInit(Encryptor* this, char* method, char* key ){
    this->key = key;
    this->cursor = 0;

    if( !strcmp(method, CESAR) ){
        (this->encryptFunction)  = & (_encrpytorEncryptCesar);
        this->decryptFunction  = & (_encrpytorDecryptCesar);
        return SUCCESS ;
    }
    if( !strcmp(method, RC4) ){
        this->encryptFunction = &_encryptorEncryptRC4;
        this->decryptFunction  = &_encryptorDecryptRC4;
        return SUCCESS;
    }
    if( !strcmp(method, VIGNERE) ){
        this->encryptFunction =  & _encryptorEncryptVignere;
        this->decryptFunction  = &_encryptorDecryptVignere;
        return SUCCESS;
    }
    fprintf(stderr, "unknow encryption method \n");
    return FAILURE;
}

void encryptorEncrypt(Encryptor* this,char* msg, size_t size){

}

void encryptadorDecrpyt(Encryptor* this,char* msg, size_t size);

void encryptorReset(Encryptor* this){
    this->cursor = 0;
}
void encrpytorUninit(Encryptor* this){
    this->key = NULL;
    this->cursor = 0;
}



void _encrpytorCesar(Encryptor* this,char* msg, size_t size){

}
void _encryptorRC4(Encryptor* this,char* msg, size_t size);
void _encryptorVignere(Encryptor* this,char* msg, size_t size);