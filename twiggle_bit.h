/*************************************************************************************************************************
​ * 
​ ​*​ ​This header file includes a function prototype which takes​ an unsigned int as a input along with bit to be changed and operation
   to be performed
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :​August 30, 2022 
 * @file name : twiggle_bit.h
 * @file_description:  Twiggle the bit based on the input ie, clear,set and toggle operation
​ ​* @return the unsigned int with changed bit
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
uint32_t twiggle_bit(uint32_t n, int bit, operation op);
