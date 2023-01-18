#include <stdio.h>
#include <stdint.h>

/* ***************************************************************
​*​ ​
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :​August 30, 2022 
 * @file name : grab_three_bits.c
 * @file_description: Returns three bits from the input value, shifted down
​ ​*​ ​@param​ ​input: ​unsigned 32 bit integer as an input
​ ​*​ ​@param​ ​bit: which indicates the start bit from where the bits are grabbed
​ ​*​ ​@return​ ​unsigned integer which is 3 bit grabbed from the input value shifted down
********************************************************************
*/
uint32_t grab_three_bits(uint32_t input, int start_bit)
{
	if((input < 0) || (input > 0xFFFFFFFF) || (start_bit > 29) || (start_bit < 0)){
	        							// checking for boundary condition
		return -1;
	}
	
    uint32_t a = 0x0007 << start_bit;                              // logic for grab 3 bit and return
    uint32_t b = input & a;
    uint32_t grabed_bit = b >> start_bit;
    return grabed_bit;
    
}