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
    size_t cursor;
    char* key;
    void (*function)(struct Encrypter*, char*, size_t, int);
    unsigned char r[ASCII_SIZE];
    unsigned int j;
    unsigned int i;
}Encrypter;

/*
 * Constructor
 */
int encrypterInit(Encrypter* this, char* method, char* key);
/*
 * Cipher msg.
 */
void encrypterEncrypt(Encrypter* this, char* msg, size_t size);
/*
 *  Decipher msg.
 */
void encrypterDecrypt(Encrypter* this, char* msg, size_t size);
/*
 * Restart the cursors and iterators.
 */
void encrypterReset(Encrypter* this);
/*
 * Destructor
 */
void encrypterUninit(Encrypter* this);


#endif  // COMMON_ENCRYPTER_H_
