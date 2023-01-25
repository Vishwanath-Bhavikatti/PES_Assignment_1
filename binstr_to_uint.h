/*************************************************************************************************************************
​ * 
​ ​*​ ​This header file includes a function prototype for converting a binary string to an unsigned integer. constant binary
 * string is passed as an input parameter and the function returns unsigned integer in decimal format. In case of error returns -1
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :​January 20, 2023 
 * @file name : binstr_to_uint.h
 * 
 *                     
​ 
 ************************************************************************************************************************
​ ​*/ 

#include <stdio.h>
#include <stdint.h>

int binstr_to_uint(const char *str);    //calling logic function from .c file