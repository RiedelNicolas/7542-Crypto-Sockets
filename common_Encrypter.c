//
// Created by riedel on 17/10/20.
//

#include "common_Encrypter.h"
#include <stdlib.h> //for ATOI
#define SUCCESS 0
#define FAILURE -1
#define ENCRYPT_MODE  1
#define DECRYPT_MODE  -1

//Privadas

void _encrpyterCesar(Encrypter* this, char* msg, size_t size, int mode);
void _encrypterRC4(Encrypter* this, char* msg, size_t size,  int mode );
void _encrypterVignere(Encrypter* this, char* msg, size_t size, int mode);

//publicas
int encrypterInit(Encrypter* this, char* method, char* key ){
    this->key = key;
    this->cursor = 0;

    if( !strcmp(method, CESAR) ){
        this->function  = & _encrpyterCesar;
        return SUCCESS ;
    }
   /* if( !strcmp(method, RC4) ){
        this->function = &_encrypterRC4;
        return SUCCESS;
    }*/
    if( !strcmp(method, VIGNERE) ){
        this->function =  & _encrypterVignere;
        return SUCCESS;
    }
    fprintf(stderr, "unknow encryption method \n");
    return FAILURE;
}

void encrypterEncrypt(Encrypter* this, char* msg, size_t size){
    this->function(this,msg,size, ENCRYPT_MODE);
    (this->cursor)+=size;
}

void encrypterDecrypt(Encrypter* this, char* msg, size_t size){
    this->function(this,msg,size, DECRYPT_MODE);
    (this->cursor)+=size;
}

void encrypterReset(Encrypter* this){
    this->cursor = 0;
}

void encrypterUninit(Encrypter* this){
    this->key = NULL;
    this->cursor = 0;
    this->function = NULL;
}



void _encrpytorCesar(Encrypter* this, char* msg, size_t size, int mode){
    int key = atoi(this->key);
    for (size_t i = 0; i < size ; i++){
        msg[i] += (char) ( (key*mode) ) ;
    }
}

//void _encryptorRC4(Encrypter* this, char* msg, size_t size,int mode);

void _encryptorVignere(Encrypter* this, char* msg, size_t size, int mode){
    char* key = this->key;
    size_t cursor = this->cursor;

    for (size_t i = 0; i < size ; i++){
        msg[i] +=  ( key[ (cursor%strlen(key) ) ]*mode ) ;
    }
}
