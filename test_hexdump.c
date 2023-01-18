#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "hexdump.h"

int test_hexdump()
{
   /* typedef struct 
    {
        size_t size;
        const void *loc;
        size_t nbytes;
        const char* exp_str;
    }test_data;
    const char *buf= \
    "To achieve great things, two things are needed:\n" \
    "a plan, and not quite enough time.";

    char str[1024];
    test_data tests[] = 
    {
        {sizeof(str),buf,strlen(buf)+1, "0x0000  54 6F 20 61 63 68 69 65 76 65 20 67 72 65 61 74\n0x0010  20 74 68 69 6E 67 73 2C 20 74 77 6F 20 74 68 69\n0x0020  6E 67 73 20 61 72 65 20 6E 65 65 64 65 64 3A 0A\n0x0030  61 20 70 6C 61 6E 2C 20 61 6E 64 20 6E 6F 74 20\n0x0040  71 75 69 74 65 20 65 6E 6F 75 67 68 20 74 69 6D\n0x0050  65 2E 00" },

    };
    

    const int total_tests = sizeof(tests) / sizeof(test_data);
    int passed_tests=0;
    char *test_result;

    for(int i=0;i<total_tests;i++)
    {
        *str = hexdump(str, tests[i].size, tests[i].loc, tests[i].nbytes);

        if(strcmp(str, tests[i].exp_str)==0)
        {
            test_result = "Passed";
            passed_tests++;
        }
        else
        {
            puts(str);
            puts(exp_str);
            //printf("string is %s\n\r",str);
            //printf("test string is %s\n\r",tests[i].exp_str);
        
            test_result="Failed";
         
        }
        //printf("%s: hexdump(%u, %u) returned %d, str=%s\n",test_result,tests[i].num, tests[i].nbit, act_ret, str);
        memset(str,0,512);

    }
    printf("%s: Passed %d / %d\n", __FUNCTION__, passed_tests,total_tests);
    printf("\n");
    return(passed_tests == total_tests);*/
    char str[1024];
    const char buf[]= \
    {"To achieve great things, two things are needed:\n"
    "a plan, and not quite enough time."};
    
    const char exp_str[] = "0x0000  54 6F 20 61 63 68 69 65 76 65 20 67 72 65 61 74 \n" \
    "0x0010  20 74 68 69 6E 67 73 2C 20 74 77 6F 20 74 68 69 \n" \
    "0x0020  6E 67 73 20 61 72 65 20 6E 65 65 64 65 64 3A 0A \n" \
    "0x0030  61 20 70 6C 61 6E 2C 20 61 6E 64 20 6E 6F 74 20 \n" \
    "0x0040  71 75 69 74 65 20 65 6E 6F 75 67 68 20 74 69 6D \n" \
    "0x0050  65 2E 00 \n";

    
    char *act_str = hexdump(str, sizeof(str), buf, strlen(buf)+1);
    if(memcmp(str,exp_str,sizeof(exp_str)) == 0)
    {
        printf("Test passed\n");
    }
    else
    {
        printf("Test failed\n");
    }
    //put(hexdump(str, sizeof(str), buf, strlen(buf)+1));
    printf("Expected string: %s\n",exp_str);
    printf("Actual string: %s\n",act_str);
    for(int i = 0;str[i]!='\0';i++)
    {
        if(str[i] != exp_str[i])
        printf("%d,%x,%x\t",i,str[i],exp_str[i]);
    }
    return 1;




}



















