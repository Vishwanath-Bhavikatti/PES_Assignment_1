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
 * @credits : https://indepth.dev/posts/1019/the-simple-math-behind-decimal-binary-conversion-algorithms 
​ ​*​ ​@date​ :January 22, 2023 
 * @file name : binstr_to_uint.c
 * @file_description:  convertion of binary string to unsigned Integer in decimal format
​ ​* @param char *str: Constant Binary string as input 
​ ​*​ ​@return : Function returns an unsigned integer in a decimal format from binary string.
 * @return -1 : In case of faulty cased returning -1 
*************************************************************************************************************************
*/

int binstr_to_uint(const char *str)
{
    // Eliminating cases
    // condition for a NULL string
    {
    if(str == NULL)       
        return -1;
    }
    
    int str_len = 0;
    // length of the string is stored in str_len
    for(int i = 0;str[i]!='\0';i++)
    {
        str_len++;                  
    }
     // 0bcccc : if counts of c's > 32 or < 1 condition case
    if(str_len < 3 || str_len > 34)
    {
        return -1;                 
    }

    //condition checking if first two characters follow 0b...... notation or not
    if(str[0]!='0' || str[1]!='b')
    {
        return -1;
    }
    
    
    for(int i = 2;str[i]!='\0';i++)
    {
        // 0bcccc.. : checking if c is an invalid bit
        if(str[i] > '1' || str[i] < '0')
        {
            return -1;              
        }
    }
    
    // Logic for binstr to uint 
    
    int result = 0;
    for(int i = 2;str[i]!='\0';i++)
    {
        // current_result = (2 * prev_result) + ith element of string in integer form
        result = (result << 1) + (str[i] - '0');        
    }
    return result;          // returning the final result
}