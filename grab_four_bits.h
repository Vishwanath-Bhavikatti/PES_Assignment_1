/*************************************************************************************************************************
​ * 
​ ​*​ This header file includes a function prototype which returns four bits from the input value shifted down from the 
 * given start bit.
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :​January 20, 2023 
 * @file name : grab_four_bits.h
 ************************************************************************************************************************
​ ​*/ 

#include <stdio.h>
#include <stdint.h>

int grab_four_bits(uint32_t input, int start_bit);  //calling logic function from .c file