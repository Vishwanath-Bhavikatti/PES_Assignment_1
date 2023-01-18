#include <stdio.h>
#include <stdint.h>



/* ***************************************************************
​*​ ​Given​ ​a​ ​pointer​ ​to​ ​a​ ​char​ ​data​ ​set,​ size of the character data set, unsigned integer and number of bits to represent,
   ​this​ ​function will convert unsigned int to hexadecimal string.
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :​August 30, 2022 
 * @file name : uint_hexstr.c
 * @file_description:  convertion of unsigned integer to hexadecimal string
​ ​* @param size: Minimum size of the character data set.
​ ​*​ ​@param​ ​ptr​: ​Pointer​ ​to​ ​a​ ​data​ ​item 
​ ​*​ ​@param​ ​num: signed integer number 
​ ​* @param nbit: bits used to represent hex number
 *              bits must be one of the values 4, 8, 16, or 32, corresponding to 1, 2, 4, or 8 hexadecimal digits. 
​ ​*​ ​@return​ ​the length of the character array 
*/
int uint_to_hexstr(char *ptr, size_t size, uint32_t num, uint8_t nbit)
{
	
	if(ptr == NULL)
    {
        return -1;
    }
    if((nbit == 0) || ((nbit & 3) != 0) || (num >= 1ULL<<nbit) || ((size_t)((nbit>>2) + 3) > size) || (nbit > 32))
    {                                                                  // condition to check if input bit is zero
        
        return -1;
    }
	// Logic to convert unsigned integer to hex in a char array 
    
    int bit = nbit>>2;
    int bin[bit];
    int index = bit -1;
    while(index >= 0)
    {
        bin[index] = num & 0xf; 						// Number logical and with 15 
        num = num >> 4; 							//right shifted by 4 or divide by 16
        index--;
    }
        
    ptr[0] = '0';
    ptr[1] = 'x';
    
    for(int i = 2;i<bit+3;i++)
    {
        if(bin[i-2] < 10)
        {
        ptr[i] = bin[i-2] + '0';
        }
        else if(bin[i-2] >= 10)
        {
            ptr[i] = bin[i-2] + '7'; 					// adding 7,as ascii value of 7 is 55, so if bin[i-2]=10 then 10+55 =65 which is ascii value of A.
        }
            
    }
    ptr[bit+2] = '\0';
        
    
    int count = 0;
    
    for(int i =0;ptr[i]!='\0';i++)
    {
        count++;
    }
    return count;
        
    
    
    
}
