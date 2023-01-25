/*
*********************************************************************************************
* @header file included : stdio.h, stdint.h
  
********************************************************************************************
*/
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>



/**********************************************************************************************************************
​ *
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :​January 22, 2023 
 * @file name : int_to_binstr.c
 * @file_description: convertion of signed integer to binary string
​ ​* @param size: Minimum size of the character data set.
​ ​*​ ​@param​ ​ptr​: ​Pointer​ ​to​ ​a​ ​data​ ​item 
​ ​*​ ​@param​ ​num: signed integer number 
​ ​* @param nbit: bits used to represent binary number
​ ​*​ ​@return​ ​the length of the character array 
*************************************************************************************************************************
*/

int int_to_binstr(char *ptr, size_t size, int32_t num, uint8_t nbit)
{
    //Condition for input NULL string 
    if(ptr == NULL)
    {
        return -1;
    }
    // checking whether number can be represented using n bits or not for +ve numbers
    else if(num>=0 && (num >= (1LL<<(nbit-1))) )  
    {
        ptr[0]='\0';
        return -1;
    }
    // if the number is -ve then taking its +ve value to check whether it can be represented using given nbits
    else if(num<0 && ((-num) > (1LL<<(nbit-1))) ) 
    {
        ptr[0]='\0';
        return -1;
    }
    // condition to check if input bit is zero or insufficient size or bits crossing the range
    else if((nbit == 0) || ((size_t)nbit + 3 > size) || (nbit > 32))
    {                                                                  
        ptr[0]='\0';
        return -1;
    }
    else
    {    
        //creating an Integer array of size nbit
        int bin[nbit];
        int index = nbit -1; // taking index values considering it starts from 0
                                                                                                                                                              
        while(index >= 0)
        {                                                         
         // Using bitwise & and right shift the number by 1 i.e(/2), to get binary number in an array
            bin[index] = num&1;
            num = num >> 1;
            index--;
        }
        // uppending string with 0b
        ptr[0] = '0';                                                             
        ptr[1] = 'b';

        // converting integer array to string array                                              
        for(int i = 2;i<nbit+3;i++)
        {                                               
            ptr[i] = bin[i-2] + '0';
        }
        ptr[nbit+2] = '\0';
   
        int count = 0;                                       
        // To get the count of the character array
        for(int i =0;ptr[i]!='\0';i++)
        {
            count++;
        }
        return count;

    }

}