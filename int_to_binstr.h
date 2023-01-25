/*************************************************************************************************************************
​ * 
​ ​*​ ​This header file includes a function prototype which takes​ ​pointer​ ​to​ ​a​ ​char​ ​data​ ​set,​ size of the character data set, 
    signed integer and number of bits to represent as an input parameters, and function will convert signed int to 
    binary string and return the length of the binary string.
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :​January 22, 2023 
 * @file name : int_to_binary.h
 * @file_description:  convertion of signed integer to binary string
​ ​* @return character array of binary string 
​ 
 ************************************************************************************************************************
​ ​*/ 

#include <stdio.h>
#include <stdint.h>
#include<stddef.h>

int int_to_binstr(char *ptr, size_t size, int32_t num, uint8_t nbit);   //calling logic function from .c file