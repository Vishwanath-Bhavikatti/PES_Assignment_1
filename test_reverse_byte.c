#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "reverse_byte.h"

int test_reverse_byte()
{
    typedef struct 
    {
        uint8_t input;
        uint8_t exp_ret;

    }test_data;
    
test_data tests[] = 
{
    {18,72},
    {0,0},
    {1,128},
    {255,255},
    //{300,-1},
    

    
};
const int total_tests = sizeof(tests) / sizeof(test_data);
int passed_tests=0;
char *test_result;
int act_ret;

for(int i=0;i<total_tests;i++)
{
    act_ret = reverse_byte(tests[i].input);

    if(act_ret == tests[i].exp_ret)
    {
        test_result = "Passed";
        passed_tests++;
    }
    else
    {
       // printf("string is %s\n\r",str);
       // printf("test string is %s\n\r",tests[i].exp_str);
        
        test_result="Failed";
         
    }
    printf("%s: reverse_byte(%u) returned %d\n",test_result,tests[i].input, act_ret);
    
}
printf("%s: Passed %d / %d\n", __FUNCTION__, passed_tests,total_tests);
printf("\n");
return(passed_tests == total_tests);



}