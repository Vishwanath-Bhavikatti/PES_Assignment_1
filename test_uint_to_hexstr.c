#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "uint_to_hexstr.h"

int test_uint_to_hexstr()
{
    typedef struct 
    {
        size_t size;
        uint32_t num;
        uint8_t nbit;
        int exp_ret;
        const char* exp_str;
    }test_data;
    
char str[512];
test_data tests[] = 
{
    {sizeof(str), 18, 8, 4, "0x12"},
    {sizeof(str), 18, 16, 6, "0x0012"},
    {sizeof(str), 65400, 16, 6, "0xFF78"},
    {sizeof(str), 310, 16, 6, "0x0136"},
    {sizeof(str), 18, 7, -1, ""},
    {sizeof(str), 16, 4, -1, ""},

    {sizeof(str), 4294967295, 32, 10, "0xFFFFFFFF"},
    {sizeof(str), 4294967294, 32, 10, "0xFFFFFFFE"},
    {sizeof(str), 0, 4, 3, "0x0"},
    {sizeof(str), 1, 4, 3, "0x1"},
    {sizeof(str), 15, 4, 3, "0xF"},
    {sizeof(str), 65400, 8, -1, ""},
    {sizeof(str), -65400, 16, -1, ""},


    {0, 18, 8, -1, ""},
    {1, 18, 8, -1, ""},
    {2, 18, 8, -1, ""},
    {4, 18, 8, -1, ""},
    {5, 18, 8, 4, "0x12"},

    

    {sizeof(str), 16, 33, -1, ""},
};
const int total_tests = sizeof(tests) / sizeof(test_data);
int passed_tests=0;
char *test_result;
int act_ret;

for(int i=0;i<total_tests;i++)
{
    act_ret = uint_to_hexstr(str,tests[i].size,tests[i].num,tests[i].nbit);

    if(act_ret == tests[i].exp_ret && strcmp(str, tests[i].exp_str)==0)
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
    printf("%s: uint_to_hexstr(%u, %u) returned %d, str=%s\n",test_result,tests[i].num, tests[i].nbit, act_ret, str);
    memset(str,0,512);
}
printf("%s: Passed %d / %d\n", __FUNCTION__, passed_tests,total_tests);
printf("\n");
return(passed_tests == total_tests);



}