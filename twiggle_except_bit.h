/*************************************************************************************************************************
​ * 
​ ​*​ ​This header file includes a function prototype which takes​ an unsigned int as a input along with bit which will be kept
  as it is and rest all bits to be twiggled according to the operation.
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :​January 22, 2023 
 * @file name : twiggle_except_bit.h
 * @file_description:  Twiggle all the bits except the given bit based on the input ie, clear,set and toggle operation
​ ​* @return the unsigned int with changed bits
​ 
 ************************************************************************************************************************
​ ​*/ 


#include <stdio.h>
#include <stdint.h>

typedef enum{
    clear,
    set,
    toggle
}operation;
uint32_t twiggle_except_bit(uint32_t input, int bit, operation op);  //calling logic function from .c file
