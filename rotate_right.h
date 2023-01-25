/*************************************************************************************************************************
​ * 
​ ​*​ ​This header file includes a function prototype that right shifts a given unsigned 8 bit int input based on the given places.
 *                     It does so in a circular fashion.
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :​January 23, 2023 
 * @file name : rotate_right.h
 * @file_description:  right shift in a circular fashion
​ 
 ************************************************************************************************************************
​ ​*/ 

#include <stdio.h>
#include <stdint.h>

uint8_t rotate_right(uint8_t input, uint8_t places);         //calling logic function from .c file