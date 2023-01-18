#include<stdio.h>
#include<stdint.h>
#include "int_to_hexchar.h"
//#include<string.h>
#define line 16

char *hexdump(char *str, size_t size, const void *loc, size_t nbytes)
{
    if(str == NULL)
    {
        return NULL;
    }
    char *s = str;
    const uint8_t *buf = (const uint8_t*)loc;
    
    *s= '\0';
    if(size < (nbytes/line) * 9 + nbytes * 3 + 1)
    {
        return str;
    }
    if(nbytes >= 0x10000)
    {
        return str;
    }
    
    for(int i = 0; (size_t)i < nbytes; i+=line)
    {
        *s++ = '0';
        *s++ = 'x';
        *s++ = int_to_hexchar((i & 0xF000) >> 12);
        *s++ = int_to_hexchar((i & 0x0F00) >> 8);
        *s++ = int_to_hexchar((i & 0x00F0) >> 4);
        *s++ = int_to_hexchar(i & 0x000F);
        *s++ = ' ';
        *s++ = ' ';
        for(int j = 0;j < line && (size_t)(i+j) < nbytes; j++)
        {
            *s++ = int_to_hexchar(buf[i+j] >> 4);
            *s++ = int_to_hexchar(buf[i+j] & 0x0f);
            *s++ = ' ';
        }
        *s++ ='\n';
        
    }
    *s++ = '\0';
    return str;
}
