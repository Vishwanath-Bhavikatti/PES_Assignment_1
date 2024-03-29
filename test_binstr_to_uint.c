#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "binstr_to_uint.h"

/*
*********************************************************************************************************************
​ *
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
 * @credits : I got motivated by my friend Ajay kandagal, Who showed me the approach of writing test cases in 
              Structured way.
​ ​*​ ​@date​ :January 22, 2023 
 * @file name : test_binstr_to_uint
 * @file_description:  The test finction consists of variety of test cases which I thought of including Boundary test cases
 *                     for the logic function binstr_to_uint.c
​ ​* 
 * @return 0 : In case of faulty cased returning 0
*************************************************************************************************************************
*/

int test_binstr_to_uint()
{
    // defining a structure for test cases, each structure corresponds to a test case
    typedef struct                          
    {
        const char *bin_str;
        int exp_ret;
    }test_data;
    

test_data tests[] = 
{
    //Given test cases from Assignment
    {"", -1},
    {"0b00", 0},
    {"0b05100", -1},
    {"0b01", 1},
    {"0b110",6},

    // Boundary test cases
    {"0b", -1},
    {"0b00000000000000000000000000000000", 0},
    {"0b11111111111111111111111111111111", 4294967295},
    {"0b111111111111111111111111111111111", -1},

    //Illegal binary string
    {"0b1234", -1},
    {"0b000/11", -1},
    {"0b*11#", -1},
    {"0x0011", -1},
    {"0B1111", -1}
    
};
const int total_tests = sizeof(tests) / sizeof(test_data);
int passed_tests=0;
char *test_result;
int act_ret;
//Taking the actual result and comparing with the expected result and printing test case status as passed/ Failed
for(int i=0;i<total_tests;i++)
{
    act_ret = binstr_to_uint(tests[i].bin_str);

    if(act_ret == tests[i].exp_ret)
    {
        test_result = "Passed";
        passed_tests++;
    }
    else
    {
       printf("act_ret is %d\n\r",act_ret);
       printf("exp_ret is %d\n\r",tests[i].exp_ret);
        
        test_result="Failed";
         
    }
    printf("%s: binstr_to_uint(%s) returned %d\n",test_result,tests[i].bin_str,act_ret);
    //memset(str,0,512);
}
printf("%s: Passed %d / %d\n", __FUNCTION__, passed_tests,total_tests);
printf("\n");
return(passed_tests == total_tests);



}