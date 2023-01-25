#include <stdio.h>
#include <stdint.h>

/* ***************************************************************
​ *​ @Function Description : Returns a decimal unsigned integer for a given constant hexadecimal string.  
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :​January 22, 2023
 * @file name : hexstr_to_uint.c
​ ​* @param char *str: Constant hex string as an input 
​ ​*​ ​@return : Function returns an unsigned integer in a decimal format from hexadecimal string.
 * @returns -1 : In case of faulty case.
*/
int hexstr_to_uint(const char *str)
{
    // Eliminating cases
    // condition for a NULL string
    if(str == NULL)       
    {
        return -1;
    }
    
    int str_len = 0;
     // length of the string is stored in str_len variable
    for(int i = 0;str[i]!='\0';i++)
    {
        str_len++;                 
    }
    
    // 0bcccc : if counts of c's > 8 condition which exceeds the limit of 32 bit.
    if(str_len < 3 || str_len > 10)
    {
        return -1;                  
    }
    
    // incase of bit being not in hex format returning -1
    if(str[0]!='0' && (str[1]!='x' || str[1] != 'X'))
    {
        return -1;                  
    }
    
    // 0bcccc.. : checking if c is an invalid bit
    for(int i = 2;str[i]!='\0';i++)          
    {
        if((str[i] < '0' || str[i] > '9') && ((str[i] < 'A' && str[i] < 'a') || (str[i] > 'F' && str[i] > 'f') || (str[i] > 'F' && str[i] < 'a')))
        {
            return -1;             
        }
    }
    
    // Logic for hexstr to uint 
    
    int result = 0;
    for(int i = 2;str[i]!='\0';i++)
    {
        // Take current string and multiply that element by 16 using left shift operator
        // then add it to the 4 bit equivalent of the hex char using ASCII values
        if(str[i] <= '9')                                   
        {                                                   
            result = (result << 4) | (str[i] - '0');       
        }
        else if((str[i] >= 'A') && (str[i] <= 'F'))
        {
            result = (result << 4) | (str[i] - 'A' + 10);
        }
        else if((str[i] >= 'a') && (str[i] <= 'f'))
        {
            result = (result << 4) | (str[i] - 'a' + 10);
        }
               
    }
    return result;          // returning the final result
}
