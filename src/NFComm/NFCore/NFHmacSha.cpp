// -------------------------------------------------------------------------
//    @FileName         :    NFHmacSha.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFHmacSha.cpp
//
// -------------------------------------------------------------------------

#include "NFHmacSha.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#ifndef SHA_DIGESTSIZE
#define SHA_DIGESTSIZE 20
#endif

#ifndef SHA_BLOCKSIZE
#define SHA_BLOCKSIZE 64
#endif


/* Hash a single 512-bit block. This is the core of the algorithm. */

void SHA1Transform(__u32 state[5], __u8 buffer[64])
{
    __u32 a, b, c, d, e;
    typedef union {
        unsigned char c[64];
        __u32 l[16];
    } CHAR64LONG16;

    CHAR64LONG16* block;

#ifdef SHA1HANDSOFF

    static unsigned char workspace[64];
    block = (CHAR64LONG16*)workspace; //-V1032
    //    NdisMoveMemory(block, buffer, 64);
    memcpy(block, buffer, 64);
#else
    block = (CHAR64LONG16*)buffer;
#endif
    /* Copy context->state[] to working vars */
    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    e = state[4];
    /* 4 rounds of 20 operations each. Loop unrolled. */
    R0(a, b, c, d, e, 0); R0(e, a, b, c, d, 1); R0(d, e, a, b, c, 2); R0(c, d, e, a, b, 3);
    R0(b, c, d, e, a, 4); R0(a, b, c, d, e, 5); R0(e, a, b, c, d, 6); R0(d, e, a, b, c, 7);
    R0(c, d, e, a, b, 8); R0(b, c, d, e, a, 9); R0(a, b, c, d, e, 10); R0(e, a, b, c, d, 11);
    R0(d, e, a, b, c, 12); R0(c, d, e, a, b, 13); R0(b, c, d, e, a, 14); R0(a, b, c, d, e, 15);
    R1(e, a, b, c, d, 16); R1(d, e, a, b, c, 17); R1(c, d, e, a, b, 18); R1(b, c, d, e, a, 19);
    R2(a, b, c, d, e, 20); R2(e, a, b, c, d, 21); R2(d, e, a, b, c, 22); R2(c, d, e, a, b, 23);
    R2(b, c, d, e, a, 24); R2(a, b, c, d, e, 25); R2(e, a, b, c, d, 26); R2(d, e, a, b, c, 27);
    R2(c, d, e, a, b, 28); R2(b, c, d, e, a, 29); R2(a, b, c, d, e, 30); R2(e, a, b, c, d, 31);
    R2(d, e, a, b, c, 32); R2(c, d, e, a, b, 33); R2(b, c, d, e, a, 34); R2(a, b, c, d, e, 35);
    R2(e, a, b, c, d, 36); R2(d, e, a, b, c, 37); R2(c, d, e, a, b, 38); R2(b, c, d, e, a, 39);
    R3(a, b, c, d, e, 40); R3(e, a, b, c, d, 41); R3(d, e, a, b, c, 42); R3(c, d, e, a, b, 43);
    R3(b, c, d, e, a, 44); R3(a, b, c, d, e, 45); R3(e, a, b, c, d, 46); R3(d, e, a, b, c, 47);
    R3(c, d, e, a, b, 48); R3(b, c, d, e, a, 49); R3(a, b, c, d, e, 50); R3(e, a, b, c, d, 51);
    R3(d, e, a, b, c, 52); R3(c, d, e, a, b, 53); R3(b, c, d, e, a, 54); R3(a, b, c, d, e, 55);
    R3(e, a, b, c, d, 56); R3(d, e, a, b, c, 57); R3(c, d, e, a, b, 58); R3(b, c, d, e, a, 59);
    R4(a, b, c, d, e, 60); R4(e, a, b, c, d, 61); R4(d, e, a, b, c, 62); R4(c, d, e, a, b, 63);
    R4(b, c, d, e, a, 64); R4(a, b, c, d, e, 65); R4(e, a, b, c, d, 66); R4(d, e, a, b, c, 67);
    R4(c, d, e, a, b, 68); R4(b, c, d, e, a, 69); R4(a, b, c, d, e, 70); R4(e, a, b, c, d, 71);
    R4(d, e, a, b, c, 72); R4(c, d, e, a, b, 73); R4(b, c, d, e, a, 74); R4(a, b, c, d, e, 75);
    R4(e, a, b, c, d, 76); R4(d, e, a, b, c, 77); R4(c, d, e, a, b, 78); R4(b, c, d, e, a, 79);
    /* Add the working vars back into context.state[] */
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
    /* Wipe variables */
    a = b = c = d = e = 0; //-V1001
}


/* SHA1Init - Initialize new context */

void SHA1Init(SHA1_CTX* context)
{
    /* NFPebbleSha1 initialization constants */
    context->state[0] = 0x67452301;
    context->state[1] = 0xEFCDAB89;
    context->state[2] = 0x98BADCFE;
    context->state[3] = 0x10325476;
    context->state[4] = 0xC3D2E1F0;
    context->count[0] = context->count[1] = 0;
}


/* Run your data through this. */

void SHA1Update(SHA1_CTX* context, unsigned char* data, __u32 len)
{
    __u32 i, j;

    j = context->count[0];
    if ((context->count[0] += len << 3) < j)
        context->count[1]++;
    context->count[1] += (len >> 29);
    j = (j >> 3) & 63;
    if ((j + len) > 63) {
        //        NdisMoveMemory(&context->buffer[j], data, (i = 64-j));
        memcpy(&context->buffer[j], data, (i = 64 - j));
        SHA1Transform(context->state, context->buffer);
        for (; i + 63 < len; i += 64) {
            SHA1Transform(context->state, &data[i]);
        }
        j = 0;
    }
    else i = 0;
    //    NdisMoveMemory(&context->buffer[j], &data[i], len - i);
    memcpy(&context->buffer[j], &data[i], len - i);
}


/* Add padding and return the message digest. */

void SHA1Final(unsigned char digest[20], SHA1_CTX* context)
{
    __u32 i, j;
    unsigned char finalcount[8];

    for (i = 0; i < 8; i++) {
        finalcount[i] = (unsigned char)((context->count[(i >= 4 ? 0 : 1)]
                >> ((3 - (i & 3)) * 8)) & 255);  /* Endian independent */
    }
    SHA1Update(context, (unsigned char *)"\200", 1);
    while ((context->count[0] & 504) != 448) {
        SHA1Update(context, (unsigned char *)"\0", 1);
    }
    SHA1Update(context, finalcount, 8);  /* Should cause a SHA1Transform() */
    for (i = 0; i < 20; i++) {
        digest[i] = (unsigned char)
                ((context->state[i >> 2] >> ((3 - (i & 3)) * 8)) & 255);
    }
    /* Wipe variables */
    i = j = 0;
    //    NdisZeroMemory(context->buffer, 64);
    //    NdisZeroMemory(context->state, 20);
    //    NdisZeroMemory(context->count, 8);
    //    NdisZeroMemory(&finalcount, 8);
    memset(context->buffer, 0x00, 64);
    memset(context->state, 0x00, 20);
    memset(context->count, 0x00, 8);
    memset(&finalcount, 0x00, 8);

#ifdef SHA1HANDSOFF  /* make SHA1Transform overwrite its own static vars */
    SHA1Transform(context->state, context->buffer);
#endif
}



/* Function to print the digest
打印输出*/
void pr_sha(FILE* fp, unsigned char* s, int t)
{
    int i;

    for (i = 0; i<t; i++)
        printf("%02x", s[i]);
    printf("\n");

}

void truncate
        (
                char* d1, /* data to be truncated */
                char* d2, /* truncated data */
                int len /* length in bytes to keep */
        )
{
    int i;
    for (i = 0; i < len; i++) d2[i] = d1[i];
}

/* Function to compute the digest
加密算法的主要操作函数 */
void hmac_sha
        (
                char* k,    /* 秘钥 secret key */
                int lk,     /*  秘钥长度 length of the key in bytes */
                char* d,    /* 数据 data */
                int ld,     /*  数据长度 length of data in bytes */
                char* out,  /* 输出的字符串 output buffer, at least "t" bytes */
                int t
        )
{
    SHA1_CTX ictx, octx;
    char isha[SHA_DIGESTSIZE], osha[SHA_DIGESTSIZE];
    char key[SHA_DIGESTSIZE];
    char buf[SHA_BLOCKSIZE];
    int i;

    if (lk > SHA_BLOCKSIZE)
    {
        SHA1_CTX tctx;
        SHA1Init(&tctx);
        SHA1Update(&tctx, (unsigned char*)k, lk);
        SHA1Final((unsigned char*)key, &tctx);

        k = key;
        lk = SHA_DIGESTSIZE;
    }

    /**** Inner Digest ****/

    SHA1Init(&ictx);

    /* Pad the key for inner digest */
    for (i = 0; i < lk; ++i) buf[i] = k[i] ^ 0x36;
    for (i = lk; i < SHA_BLOCKSIZE; ++i) buf[i] = 0x36;

    SHA1Update(&ictx, (unsigned char*)buf, SHA_BLOCKSIZE);
    SHA1Update(&ictx, (unsigned char*)d, ld);

    SHA1Final((unsigned char*)isha, &ictx);

    /**** Outter Digest ****/

    SHA1Init(&octx);

    /* Pad the key for outter digest */

    for (i = 0; i < lk; ++i) buf[i] = k[i] ^ 0x5C;
    for (i = lk; i < SHA_BLOCKSIZE; ++i) buf[i] = 0x5C;

    SHA1Update(&octx, (unsigned char*)buf, SHA_BLOCKSIZE);
    SHA1Update(&octx, (unsigned char*)isha, SHA_DIGESTSIZE);

    SHA1Final((unsigned char*)osha, &octx);

    /* truncate and print the results */
    t = t > SHA_DIGESTSIZE ? SHA_DIGESTSIZE : t;
    truncate(osha, out, t);
    pr_sha(stdout, (unsigned char*)out, t);
}

std::string NFHmacSha::sha1str(const std::string& key, const std::string& data)
{
    int hmaclen = 20;
    char hmac_buf[32] = { 0 };
    hmac_sha((char*)key.data(), (int)key.length()
            , (char*)data.data(), (int)data.length(), hmac_buf, hmaclen);

    return std::string (hmac_buf, hmaclen);
}
