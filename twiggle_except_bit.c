#include <stdio.h>
#include <stdint.h>
#include "twiggle_except_bit.h"

/* ***************************************************************
​*​ ​
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :​January 20, 2023 
 * @file name : twiggle_except_bit.c
 * @file_description:  Changes all the bits of the input value, without changing the single input bit based on enum datatype.
​ ​*​ ​@param​ ​input: ​unsigned 32 bit integer as an input 
​ ​*​ ​@param​ ​bit: integer bit which needs to be kept as it is.
​ ​* @param op: enumerated datatype for changing the bit based on set, clear and toggle 
​ ​*​ ​@return​ ​unsigned integer with all the bits changed as per the operation except a given bit 
********************************************************************
*/

uint32_t twiggle_except_bit(uint32_t input, int bit, operation op)
{
	if((bit > 31) || (bit < 0) || (input > 0xFFFFFFFF))
    {                										// if input is larger than 32 bit return -1
		return -1;
	}
	uint32_t setdata,cleared,toggled;
    switch (op)
    {
    case set: 
        setdata = input | (~(1<<bit)); //Negating the result of 1 left shifyed to given bit position and doing OR operation
        return setdata;            // to get all the bits set except the given bit 
        break;
    case clear:
        cleared = input & (1<<bit); // 1 is shifted to its left by number of bits and the doing AND operation 
        return cleared;         // to get all the bits cleared except the given bit
        break;
    case toggle:
        toggled = input ^ (~(1<<bit)); // Negating the result of 1 shifted to its left by number of bits and the doing XOR operation 
        return toggled;                // to get all the bits cleared except the given bit
        break;
    default:
        return -1;
        break;
    }
}
