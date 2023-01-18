#include<stdio.h>
#include<stdint.h>
#include "test_binstr_to_uint.h"
#include "test_int_to_binstr.h"
#include "test_uint_to_hexstr.h"
#include "test_twiggle_bit.h"
#include "test_grab_three_bits.h"
#include "test_hexdump.h"
#include "test_reverse_byte.h"

int main()
{
    int res1;
    res1 = test_binstr_to_uint();
    //res1 = test_int_to_binstr();
    //res1 = test_uint_to_hexstr();
    //res1 = test_twiggle_bit();
    //res1 = test_grab_three_bits();
    //res1 = test_hexdump();
    //res1 = test_reverse_byte();
    if(res1 == 1)
    {
        printf("Success..!\n");
    }
    else if(res1 == 0)
    {
         printf("Failed..!\n");
    }
    
    return 0;
}