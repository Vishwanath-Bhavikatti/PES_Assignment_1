#include <stdio.h>
#include <stdint.h>

/* ***************************************************************
​*​ ​
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :​January 20, 2023 
 * @file name : grab_four_bits.c
 * @file_description: Returns four bits from the input value, shifted down
​ ​*​ ​@param​ ​input: ​unsigned 32 bit integer as an input
​ ​*​ ​@param​ ​bit: which indicates the start bit from where the bits are grabbed
​ ​*​ ​@return​: returns an ​unsigned integer which is 4 bit grabbed from the input value shifted down
********************************************************************
*/
uint32_t grab_four_bits(uint32_t input, int start_bit)
{
    // checking for boundary condition
	if((input < 0) || (input > 0xFFFFFFFF) || (start_bit > 28) || (start_bit < 0)){
	        							
		return -1;
	}
	// logic for grab 4 bit and return
    // Masking the bits from start bit by left shifting 0x000f 
    uint32_t shifted_bits = 0x000F << start_bit;                             
    uint32_t result = input & shifted_bits;
    //Again right shifting the masked bits to get the result
    uint32_t grabed_bit = result >> start_bit;
    return grabed_bit;
    
}