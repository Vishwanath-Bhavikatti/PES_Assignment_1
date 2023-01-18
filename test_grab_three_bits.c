#include<stdio.h>
#include<stdint.h>
#include "grab_three_bits.h"

int test_grab_three_bits()
{
    typedef struct 
    {
        uint32_t input;
        int start_bit;
        uint32_t exp_ret;
    }test_data;
    
test_data tests[] = 
{
    {0x7337, 6, 4},
    {0x7337, 7, 6},
    {10,2,2},
    {10,30,0xFFFFFFFF},
    
};
const int total_tests = sizeof(tests) / sizeof(test_data);
int passed_tests=0;
char *test_result;
int act_ret;

for(int i=0;i<total_tests;i++)
{
    act_ret = grab_three_bits(tests[i].input,tests[i].start_bit);

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
    printf("%s: grab_three_bits(%u, %d) returned 0x%X\n",test_result,tests[i].input, tests[i].start_bit, act_ret);
    //memset(str,0,512);
}
printf("%s: Passed %d / %d\n", __FUNCTION__, passed_tests,total_tests);
printf("\n");
return(passed_tests == total_tests);



}