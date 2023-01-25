#include <stdio.h>
#include <stdint.h>
#define nbit 8
#define mask 7
/*
*********************************************************************************************************************
​ *
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :​January 23, 2023 
 * @file name : rotate_right.c
 * @file_description:  The function right shifts a given unsigned 8 bit int input based on the given places.
 *                     It does so in a circular fashion.
​ ​* @param input: Unsigned 8 bit integer input.
​ ​*​ ​@param​ ​places​: unsigned 8 bit value to shift right
​ ​*​ ​@return​ ​the right shifted 8 bit unsigned integer.
*************************************************************************************************************************
*/

uint8_t rotate_right(uint8_t input,uint8_t places)
{
    //checking if an input is not an 8 bit number and returning -1 in unsatisfied condition 
    if(input >= (1ULL << nbit))
    {
        return -1;  
    }
    //logic to shift_right in a circular fashion
    //First the input value is shifted right based on the places given by user
    //second input is shifted left by 8 minus the place provided by the user to get the LSB's to move to the MSB side
    //Doing OR operation between First and second result gives circularly right shifted value 
    
    places = places & mask; // taking a rwmainder values in case if places > 8
    uint8_t shifted_result = (input >> places) | (input << (nbit - places)); 
    return shifted_result;
    
    
}
