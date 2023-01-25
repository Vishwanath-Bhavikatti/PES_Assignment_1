/*************************************************************************************************************************
​ * 
​ ​*​ ​This header file includes a function prototype which returns a decimal unsigned integer for a given constant hexadecimal string. 
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :​January 22, 2023
 * @file name : hexstr_to_uint.h
 * @file_description:  convertion of hexadecimal string to an integer 
​ 
 ************************************************************************************************************************
​ ​*/ 

#include <stdio.h>
#include <stdint.h>

int hexstr_to_uint(const char *str);        //calling logic function from .c file