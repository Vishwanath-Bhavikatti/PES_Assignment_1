#include<stdio.h>
#include<stdint.h>
//#include<string.h>
#include "twiggle_bit.h"

int test_twiggle_bit()
{
    typedef struct 
    {
        uint32_t input;
        int bit;
        operation op;
        uint32_t exp_ret;
    }test_data;
    
//char str[512];
test_data tests[] = 
{
    {0, 0, set, 1},
    {0, 3, set, 8},
    {0x7337, 5, toggle, 0x7317},
    {65535, 32, clear, 0xFFFFFFFF},
    {18, 5, set, 50},
    {0xFFFFFFFF, 31, toggle, 0x7FFFFFFF},
    
};
const int total_tests = sizeof(tests) / sizeof(test_data);
int passed_tests=0;
char *test_result;
int act_ret;

for(int i=0;i<total_tests;i++)
{
    act_ret = twiggle_bit(tests[i].input,tests[i].bit,tests[i].op);

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
    printf("%s: twiggle_bit(%u, %d) returned 0x%x\n",test_result,tests[i].input, tests[i].bit, act_ret);
    //memset(str,0,512);
}
printf("%s: Passed %d / %d\n", __FUNCTION__, passed_tests,total_tests);
printf("\n");
return(passed_tests == total_tests);



}