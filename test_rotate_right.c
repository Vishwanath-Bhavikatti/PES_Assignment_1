#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "rotate_right.h"

/*
*********************************************************************************************************************
​ *
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
 * @credits : I got motivated by my friend Ajay kandagal, Who showed me the approach of writing test cases in 
              Structured way.
​ ​*​ ​@date​ :January 23, 2023 
 * @file name : test_rotate_right.c
 * @file_description:  The test finction consists of variety of test cases which I thought of including Boundary test cases
 *                     for the logic function rotate_right.c
​ ​* 
 * @return 0 : In case of faulty cased returning 0
*************************************************************************************************************************
*/
int test_rotate_right()
{
    typedef struct 
    {
        uint8_t input;
        uint8_t places;
        uint8_t exp_ret;

    }test_data;
    
test_data tests[] = 
{
    {0b01000110,1,0b00100011},
    {0b01000110,2,0b10010001},

    //Boundary test cases
    {0b00000001,9,0b10000000},
    {0b00000011,255,0b00000110},
    {0b00000000,1,0b00000000},
        
};
const int total_tests = sizeof(tests) / sizeof(test_data);
int passed_tests=0;
char *test_result;
int act_ret;

//Taking the actual result and comparing with the expected result and printing test case status as passed/ Failed
for(int i=0;i<total_tests;i++)
{
    act_ret = rotate_right(tests[i].input,tests[i].places);

    if(act_ret == tests[i].exp_ret)
    {
        test_result = "Passed";
        passed_tests++;
    }
    else
    {    
        test_result="Failed";
         
    }
    printf("%s: rotate_right(%u,%u) returned %d\n",test_result,tests[i].input, tests[i].places,act_ret);
    
}
printf("%s: Passed %d / %d\n", __FUNCTION__, passed_tests,total_tests);
printf("\n");
return(passed_tests == total_tests);



}