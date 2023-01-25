#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "hexstr_to_uint.h"

/*
*********************************************************************************************************************
​ *
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
 * @credits : I got motivated by my friend Ajay kandagal, Who showed me the approach of writing test cases in 
              Structured way.
​ ​*​ ​@date​ :January 22, 2023 
 * @file name : test_hexstr_to_uint.c
 * @file_description:  The test finction consists of variety of test cases which I thought of including Boundary test cases
 *                     for the logic function hexstr_to_uint.c
​ ​* 
 * @return 0 : In case of faulty cased returning 0
*************************************************************************************************************************
*/
int test_hexstr_to_uint()
{
    typedef struct                         // defining a structure for test cases, each structure corresponds to a test case 
    {
        const char *hex_str;
        int exp_ret;
    }test_data;
    

test_data tests[] = 
{
    //Given test cases from Assignment
    {"", -1},
    {"0x12", 18},
    {"0x0012", 18},
    {"0xfF78", 65400},
    {"0x0136",310},

    // Boundary test cases
    {"0x", -1},
    {"0x00000000", 0},
    {"0X00000000",0},
    {"0xFFFFFFFF", 4294967295},
    {"0xFffffFFFF", -1},

    //Illegal hexary string
    {"0xfG", -1},
    {"0xfKg", -1},
    {"0xfHH",-1},
    {"0x000/11", -1},
    {"0x*1k#", -1},
    {"ffff", -1},
    {"XfffF", -1},
    
};
const int total_tests = sizeof(tests) / sizeof(test_data);
int passed_tests=0;
char *test_result;
int act_ret;

//Taking the actual result and comparing with the expected result and printing test case status as passed/ Failed
for(int i=0;i<total_tests;i++)
{
    act_ret = hexstr_to_uint(tests[i].hex_str);

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
    printf("%s: hexstr_to_uint(%s) returned %d\n",test_result,tests[i].hex_str,act_ret);
    //memset(str,0,512);
}
printf("%s: Passed %d / %d\n", __FUNCTION__, passed_tests,total_tests);
printf("\n");
return(passed_tests == total_tests);



}