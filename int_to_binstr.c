/*
*********************************************************************************************
* @header file included : stdio.h, stdint.h
  
********************************************************************************************
*/
#include <stdio.h>
#include <stdint.h>



/*
*********************************************************************************************************************
​ *
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :​January 22, 2022 
 * @file name : int_binary.c
 * @file_description:  convertion of signed integer to binary string
​ ​*​ ​@Credit :Suryakanth Sharma https://stackoverflow.com/questions/25525536/write-pow-function-without-math-h-in-c 
   power function using bitwise operators
​ ​* @param size: Minimum size of the character data set.
​ ​*​ ​@param​ ​ptr​: ​Pointer​ ​to​ ​a​ ​data​ ​item 
​ ​*​ ​@param​ ​num: signed integer number 
​ ​* @param nbit: bits used to represent binary number
​ ​*​ ​@return​ ​the length of the character array 
*************************************************************************************************************************
*/

int int_to_binstr(char *ptr, size_t size, int32_t num, uint8_t nbit)
{
    //memset(ptr,0,512);
    
    if(ptr == NULL)
    {
        return -1;
    }
    if(num>=0 && (num >= 1ULL<<(nbit-1)) )   // checking whether number can be represented using n bits or not for +ve numbers
    {
        return -1;
    }
    if(num<0 && ((~num + 1) >= 1ULL<<(nbit)))  // if the number is -ve then taking its +ve value to check whether it can be represented using given nbits
    {
        return -1;
    }
    
    if((nbit == 0) || ((size_t)nbit + 3 > size) || (nbit > 32))
    {                                                                  // condition to check if input bit is zero
        //ptr="0";
        return -1;
    }
    int bin[nbit];
    int index = nbit -1;
                                                                                                                                                              
    while(index >= 0)
    {                                                          // Using bitwise & and right shift the number by 1 i.e(/2), to get binary number in an array
        bin[index] = num&1;
        num = num >> 1;
        index--;
    }
    ptr[0] = '0';                                                               // uppending string with 0b
    ptr[1] = 'b';
                                                       
    for(int i = 2;i<nbit+3;i++)
    {                                                // converting integer array to string array
        ptr[i] = bin[i-2] + '0';
    }
    ptr[nbit+2] = '\0';
   
    
    int count = 0;                                                              // To get the count of the character array
    
    for(int i =0;ptr[i]!='\0';i++)
    {
        count++;
    }
    return count;

}
