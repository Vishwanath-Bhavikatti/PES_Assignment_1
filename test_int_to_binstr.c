#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "int_to_binstr.h"

int test_int_to_binstr()
{
    typedef struct 
    {
        size_t size;
        int32_t num;
        uint8_t nbit;
        int exp_ret;
        const char* exp_str;
    }test_data;
    
char str[512];
test_data tests[] = 
{
    {sizeof(str), 18, 8, 10, "0b00010010"},
    {sizeof(str), -1, 4, 6, "0b1111"},
    {sizeof(str), -3, 8, 10, "0b11111101"},
    {sizeof(str), 310, 4, -1, ""},
    {sizeof(str), -310, 4, -1, ""},
    {sizeof(str), 310, 16, 18, "0b0000000100110110"},
    {sizeof(str), -310, 16, 18, "0b1111111011001010"},

    {sizeof(str), 15, 4, -1, ""},
    {sizeof(str), -15, 4, 6, "0b0001"},
    {sizeof(str), -15, 5, 7, "0b10001"},
    {sizeof(str), 16, 4, -1, ""},
    {sizeof(str), 16, 5, -1, ""},

    {sizeof(str), 0, 1, 3, "0b0"},
    {sizeof(str), -1, 1, 3, "0b1"},
    {sizeof(str), -1, 2, 4, "0b11"},
    {sizeof(str), 0, 2, 4, "0b00"},
    {sizeof(str), 2, 2, -1, ""},
    {sizeof(str), -2, 2, 4, "0b10"},
    {sizeof(str), -2, 3, 5, "0b110"},

    {0, 18, 8, -1, ""},
    {1, 18, 8, -1, ""},
    {2, 18, 8, -1, ""},
    {10, 18, 8, -1, ""},
    {10, -18, 8, -1, ""},
    {11, 18, 8, 10, "0b00010010"},
    {11, -18, 8, 10, "0b11101110"},


    {sizeof(str), 0X7FFFFFFE, 32, 34, "0b01111111111111111111111111111110"},
    {sizeof(str), -0X7FFFFFFE, 32, 34, "0b10000000000000000000000000000010"},
    {sizeof(str), 0X7FFFFFFF, 31, -1, ""},
    {sizeof(str), 0X7FFFFFFF, 32, 34, "0b01111111111111111111111111111111"},
    {sizeof(str), -0X7FFFFFFF, 32, 34, "0b10000000000000000000000000000001"},

    {sizeof(str), 16, 33, -1, ""},
};
const int total_tests = sizeof(tests) / sizeof(test_data);
int passed_tests=0;
char *test_result;
int act_ret;

for(int i=0;i<total_tests;i++)
{
    act_ret = int_to_binstr(str,tests[i].size,tests[i].num,tests[i].nbit);

    if(act_ret == tests[i].exp_ret && strcmp(str, tests[i].exp_str)==0)
    {
        test_result = "Passed";
        passed_tests++;
    }
    else
    {
        
        printf("string is %s\n\r",str);
        printf("test string is %s\n\r",tests[i].exp_str);
        
        test_result="Failed";
         
    }
    printf("%s: int_to_binstr(%u, %u) returned %d, str=%s\n",test_result,tests[i].num, tests[i].nbit, act_ret, str);
    memset(str,0,512);

}
printf("%s: Passed %d / %d\n", __FUNCTION__, passed_tests,total_tests);
printf("\n");
return(passed_tests == total_tests);



}