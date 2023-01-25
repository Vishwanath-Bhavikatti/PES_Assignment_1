/*************************************************************************************************************************
​ * 
​ ​*​ ​This header file includes a function prototype which when given a string, returns a hexadecimal values of each character
 * in a string in a hex dump form 
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
 * @Credits:  https://stackoverflow.com/questions/7775991/how-to-get-hexdump-of-a-structure-data
              http://web.cecs.pdx.edu/~harry/Blitz/BlitzSrc/hexdump.c
​ ​*​ ​@date​ :​January 23, 2023 
 * @file name : hexdump.h
 * 
 *                     
​ 
 ************************************************************************************************************************
​ ​*/ 

#include <stdio.h>
#include <stdint.h>
#include<stddef.h>

char *hexdump(char *str, size_t size, const void *loc, size_t nbytes);  //calling logic function from .c file