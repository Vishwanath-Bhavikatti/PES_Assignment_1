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
​ ​*​ ​@date​ :January 22, 2023 
 * @file name : bnstr_to_uint
 * @file_description:  convertion of binary string to unsigned Integer in decimal format
​ ​* @param char *str: Constant Binary string as input 
​ ​*​ ​@return : Function returns an unsigned integer in a decimal format from binary string.
 * @return -1 : In case of faulty cased returning -1 
*************************************************************************************************************************
*/

int binstr_to_uint(const char *str)
{
    // Eliminating cases
    if(str == NULL)       // condition for a NULL string
    {
        return -1;
    }
    
    int str_len = 0;
    for(int i = 0;str[i]!='\0';i++)
    {
        str_len++;                  // length of the string is stored in str_len
    }
    
    if(str_len < 3 || str_len > 34)
    {
        return -1;                  // 0bcccc : if counts of c's > 32 condition case
    }

     
    if(str[0]!='0' || str[1]!='b')
    {
        return -1;
    }
    
    
    for(int i = 2;str[i]!='\0';i++)
    {
        if(str[i] > '1' || str[i] < '0')
        {
            return -1;              // 0bcccc.. : checking if c is an invalid bit
        }
    }
    
    // Logic for binstr to uint 
    
    int result = 0;
    for(int i = 2;str[i]!='\0';i++)
    {
        result = (result << 1) + (str[i] - '0');        // current_result = (2 * prev_result) + ith element of string in integer form
    }
    return result;          // returning the final result
}