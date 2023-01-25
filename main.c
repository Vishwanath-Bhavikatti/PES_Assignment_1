/*
*********************************************************************************************
* @header file included : It includes all the test function headers to perform the test cases
  
********************************************************************************************
*/

#include<stdio.h>
#include<stdint.h>
#include "test_binstr_to_uint.h"
#include "test_int_to_binstr.h"
#include "test_hexstr_to_uint.h"
#include "test_twiggle_except_bit.h"
#include "test_grab_four_bits.h"
#include "test_hexdump.h"
#include "test_rotate_right.h"

/*
*********************************************************************************************************************
​ *
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :January 23, 2023 

 * @file_description:  The main function calls all the logic test case function and stores the returned result in result
                    variables.
                    return 1: Successfull 
                    return 0: Failed

 *  
*************************************************************************************************************************
*/
int main()
{
    int res_fun1,res_fun2,res_fun3,res_fun4,res_fun5,res_fun6,res_fun7;
    res_fun1 = test_binstr_to_uint();
    res_fun2 = test_int_to_binstr();
    res_fun3 = test_hexstr_to_uint();
    res_fun4 = test_twiggle_except_bit();
    res_fun5 = test_grab_four_bits();
    res_fun6 = test_hexdump();
    res_fun7 = test_rotate_right();
    if((res_fun1 == 1) && (res_fun2 == 1) && (res_fun3 == 1)  && (res_fun4 == 1) && (res_fun5 == 1) && (res_fun6 == 1) && (res_fun7 == 1))
    {
        printf("Success..!\n");
    }
    else
    {
         printf("Failed..!\n");
    }
    
    return 0;
}