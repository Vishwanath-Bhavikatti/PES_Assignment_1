#include<stdio.h>
#include<stdint.h>
#include "grab_four_bits.h"

/*
*********************************************************************************************************************
​ *
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
 * @credits : I got motivated by my friend Ajay kandagal, Who showed me the approach of writing test cases in 
              Structured way.
​ ​*​ ​@date​ :January 22, 2023 
 * @file name : test_grab_four_bits.c
 * @file_description:  The test finction consists of variety of test cases which I thought of including Boundary test cases
 *                     for the logic function grab_four_bits.c
​ ​* 
 * @return 0 : In case of faulty cased returning 0
*************************************************************************************************************************
*/
int test_grab_four_bits()
{
    typedef struct 
    {
        uint32_t input;             // defining a structure for test cases, each structure corresponds to a test case 
        int start_bit;
        uint32_t exp_ret;
    }test_data;
    
test_data tests[] = 
{
    // Given test cases from Assignment
    {0x7337, 6, 12},
    {0x7337, 7, 6},
    
    //Boundary conditions
    {0xFFFFFFFF,29,0xFFFFFFFF},
    {0xFFFFFFFF,28,0xf},
    {0xFFFFFFFF,-1,0xffffffff},
    {10,30,0xFFFFFFFF},
    
};
const int total_tests = sizeof(tests) / sizeof(test_data);
int passed_tests=0;
char *test_result;
int act_ret;

//Taking the actual result and comparing with the expected result and printing test case status as passed/ Failed
for(int i=0;i<total_tests;i++)
{
    act_ret = grab_four_bits(tests[i].input,tests[i].start_bit);

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
    printf("%s: grab_four_bits(%u, %d) returned 0x%X\n",test_result,tests[i].input, tests[i].start_bit, act_ret);
    
}
printf("%s: Passed %d / %d\n", __FUNCTION__, passed_tests,total_tests);
printf("\n");
return(passed_tests == total_tests);



}