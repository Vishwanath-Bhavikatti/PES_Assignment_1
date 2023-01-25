#include<stdio.h>
#include<stdint.h>
#include "twiggle_except_bit.h"

/*
*********************************************************************************************************************
​ *
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
 * @credits : I got motivated by my friend Ajay kandagal, Who showed me the approach of writing test cases in 
              Structured way.
​ ​*​ ​@date​ :January 22, 2023 
 * @file name : test_twiggle_except_bit.c
 * @file_description:  The test finction consists of variety of test cases which I thought of including Boundary test cases
 *                     for the logic function twiggle_except_bit.c
​ ​* 
 * @return 0 : In case of faulty cased returning 0
*************************************************************************************************************************
*/
int test_twiggle_except_bit()
{
    typedef struct 
    {
        uint32_t input;
        int bit;                       // defining a structure for test cases, each structure corresponds to a test case 
        operation op;
        uint32_t exp_ret;
    }test_data;
    
test_data tests[] = 
{
    // Given test cases from Assignment
    {0, 0, set, 0xFFFFFFFE},
    {0, 3, set, 0xFFFFFFF7},
    {0x7337, 5, toggle, 0xFFFF8CE8},

    // Boundary cases
    {65535, 32, clear, 0xFFFFFFFF},
    {0xFFFFFFFE,0,clear,0},
    {0xFFFFFFFE,0,toggle,0},
    {0xFFFFFFFE,-1,clear,0xFFFFFFFF},
    {0xFFFFFFFF, 31, toggle, 0x80000000},
    
};
const int total_tests = sizeof(tests) / sizeof(test_data);
int passed_tests=0;
char *test_result;
int act_ret;

//Taking the actual result and comparing with the expected result and printing test case status as passed/ Failed
for(int i=0;i<total_tests;i++)
{
    act_ret = twiggle_except_bit(tests[i].input,tests[i].bit,tests[i].op);

    if((uint32_t)act_ret == tests[i].exp_ret)
    {
        test_result = "Passed";
        passed_tests++;
    }
    else
    {
        printf("actual return %u\n\r",act_ret);
        printf("expected return is %u\n\r",tests[i].exp_ret);
        test_result="Failed";
         
    }
    printf("%s: twiggle_except_bit(%u, %d) returned 0x%x\n",test_result,tests[i].input, tests[i].bit, act_ret);
    //memset(str,0,512);
}
printf("%s: Passed %d / %d\n", __FUNCTION__, passed_tests,total_tests);
printf("\n");
return(passed_tests == total_tests);



}