#include <stdio.h>
#include <stdint.h>
#define nbit 8
uint8_t reverse_byte(uint8_t input)
{
    if(input >= (1ULL << nbit))
    {
        return -1;
    }
    uint8_t reverse = 0;
    for(int i=0;i<nbit;i++)
    {
        reverse|= ((input >> i) & 1) << (nbit-i-1);
        
    }
    return reverse;
}
