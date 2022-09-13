// -------------------------------------------------------------------------
//    @FileName         :    NFHmacSha.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFHmacSha.h
//
// -------------------------------------------------------------------------

#pragma once

#include <string>

typedef unsigned long    __u32;
typedef unsigned char    __u8;

typedef struct
{
    __u32 state[5];
    __u32 count[2];
    __u8  buffer[64];
} SHA1_CTX;

#if defined(rol)
#undef rol
#endif

#define SHA1HANDSOFF

#define rol(value, bits) (((value) << (bits)) | ((value) >> (32 - (bits))))

/* blk0() and blk() perform the initial expand. */
/* I got the idea of expanding during the round function from SSLeay */
#ifdef __LITTLE_ENDIAN
#define blk0(i) (block->l[i] = (rol(block->l[i],24)&0xFF00FF00) \
    |(rol(block->l[i],8)&0x00FF00FF))
#else
#define blk0(i) block->l[i]
#endif
#define blk(i) (block->l[i&15] = rol(block->l[(i+13)&15]^block->l[(i+8)&15] \
    ^block->l[(i+2)&15]^block->l[i&15],1))

/* (R0+R1), R2, R3, R4 are the different operations used in NFPebbleSha1 */
#define R0(v,w,x,y,z,i) z+=((w&(x^y))^y)+blk0(i)+0x5A827999+rol(v,5);w=rol(w,30);
#define R1(v,w,x,y,z,i) z+=((w&(x^y))^y)+blk(i)+0x5A827999+rol(v,5);w=rol(w,30);
#define R2(v,w,x,y,z,i) z+=(w^x^y)+blk(i)+0x6ED9EBA1+rol(v,5);w=rol(w,30);
#define R3(v,w,x,y,z,i) z+=(((w|x)&y)|(w&x))+blk(i)+0x8F1BBCDC+rol(v,5);w=rol(w,30);
#define R4(v,w,x,y,z,i) z+=(w^x^y)+blk(i)+0xCA62C1D6+rol(v,5);w=rol(w,30);


/* Hash a single 512-bit block. This is the core of the algorithm. */

void SHA1Transform(__u32 state[5], __u8 buffer[64]);
void SHA1Init(SHA1_CTX *context);
void SHA1Update(SHA1_CTX *context, unsigned char *data, __u32 len);
void SHA1Final(unsigned char digest[20], SHA1_CTX *context);
//void hmac_sha1(unsigned char *to_mac,unsigned int to_mac_length, unsigned char *key,unsigned int key_length, unsigned char *out_mac);

void hmac_sha
        (
                char* k,    /* 秘钥 secret key */
                int lk,     /*  秘钥长度 length of the key in bytes */
                char* d,    /* 数据 data */
                int ld,     /*  数据长度 length of data in bytes */
                char* out,  /* 输出的字符串 output buffer, at least "t" bytes */
                int t
        );

class NFHmacSha
{
public:
    static std::string sha1str(const std::string& key, const std::string& data);
};

