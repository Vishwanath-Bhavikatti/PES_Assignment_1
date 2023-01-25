#include<stdio.h>

/*
*********************************************************************************************************************
​ * This is a small conversion function which I used in my hexdump.c function for converting integer to hex char
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :​January 23, 2023 
 * @file name : int_binary.c
 * @file_description:  convertion of integer to hex char
​ ​*​ ​@param​ ​num: signed integer number 
​ ​*​ ​@returns​ ​the hex char for a given integer number 
*************************************************************************************************************************
*/

int int_to_hexchar(int num)
{
    if(num < 10)
    {
        return num + '0';       // To get the ASCII value of number  < 10
    }
    else
    {
        return num + 'A' - 10;     // To get the ASCII value of number  >= 10
    }
    
    
}