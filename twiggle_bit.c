#include <stdio.h>
#include <stdint.h>
#include "twiggle_bit.h"

/* ***************************************************************
​*​ ​
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :​August 30, 2022 
 * @file name : twiggle_bit.c
 * @file_description:  Changes a single bit of the input value, without changing the other bits based on enum datatype.
​ ​*​ ​@param​ ​n: ​unsigned 32 bit integer as an input 
​ ​*​ ​@param​ ​bit: integer bit which needs to be changed
​ ​* @param op: enumerated datatype for changing the bit based on set, clear and toggle 
​ ​*​ ​@return​ ​unsigned integer with a single bit change
********************************************************************
*/

uint32_t twiggle_bit(uint32_t n, int bit, operation op)
{
	if((bit > 31) || (bit < 0) || (n > 0xFFFFFFFF))
    {                										// if input is larger than 32 bit return -1
		return -1;
	}
	
    switch (op)
    {
    case set: 
        uint32_t set_data;
        set_data = (1<<bit) | n;
        return set_data;
        break;
    case clear:
        uint32_t cleared_data;
        cleared_data = n & ~(1<<bit);
        return cleared_data;
        break;
    case toggle:
        uint32_t toggled_data;
        toggled_data = n ^ (1<<bit);
        return toggled_data;
        break;
    default:
        return -1;
        break;
    }
}
