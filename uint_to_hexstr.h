/*************************************************************************************************************************
​ * 
​ ​*​ ​This header file includes a function prototype which takes​ ​pointer​ ​to​ ​a​ ​char​ ​data​ ​set,​ size of the character data set, 
    unsigned integer and number of bits to represent as an input parameters, and function will convert unsigned int to 
    binary string and return the length of the binary string.
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :​August 30, 2022 
 * @file name : unit_binary.h
 * @file_description:  convertion of unsigned integer to binary string
​ ​* @return character array of binary string 
​ 
 ************************************************************************************************************************
​ ​*/ 

#include <stdio.h>
#include <stdint.h>

int uint_to_hexstr(char *ptr, size_t size, uint32_t num, uint8_t nbit);