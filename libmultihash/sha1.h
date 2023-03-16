/* 
** sha1.h
**
** Copyright NTT MCL, 2000.
**
** Satomi Okazaki
** Security Group, NTT MCL
** November 1999
**
**************************
** 13 December 1999.  In SHA1Transform, changed "buffer" to be const.
** In SHA1Update, changed "data to be const.  -- S.O.
*/
#ifndef __SHA1_H__
#define __SHA1_H__

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#ifndef SHA1_DIGESTSIZE
#define SHA1_DIGESTSIZE  20
#endif

#ifndef SHA1_BLOCKSIZE
#define SHA1_BLOCKSIZE   64
#endif

typedef struct {
    uint32_t state[5];
    uint32_t count[2];	/* stores the number of bits */
    unsigned char buffer[SHA1_BLOCKSIZE];
} SHA1_CTX; 

void SHA1Transform(uint32_t state[5], const unsigned char buffer[SHA1_BLOCKSIZE]);
void SHA1Init(SHA1_CTX *context);
void SHA1Update(SHA1_CTX *context, const unsigned char *data, uint32_t len);
void SHA1Final(unsigned char digest[SHA1_DIGESTSIZE], SHA1_CTX *context);

#endif /* __SHA1_H__ */
