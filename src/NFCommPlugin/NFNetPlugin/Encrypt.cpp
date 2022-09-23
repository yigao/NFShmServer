#include "Encrypt.h"
#include "NFComm/NFCore/NFPlatform.h"

int8_t g_key = 87;// 01010111;

void Encryption(char * pChar, int lenth)
{
    for (int i = 0; i < lenth; ++i){
        pChar[i] = (unsigned char)(pChar[i]^ g_key);
    }
}

void Decryption(char * pChar, int lenth)
{
    for (int i = 0; i < lenth; ++i){
        pChar[i] = (unsigned char)(pChar[i]^ g_key);
    }
}

