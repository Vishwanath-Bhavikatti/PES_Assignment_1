#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "hexdump.h"

/*
*********************************************************************************************************************
​ *
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
 * @credits : I got motivated by my friend Ajay kandagal, Who showed me the approach of writing test cases in 
              Structured way.
​ ​*​ ​@date​ :January 23, 2023 
 * @file name : test_hexdump.c
 * @file_description:  The test finction consists of variety of test cases which I thought of including Boundary test cases
 *                     for the logic hexdump.c
​ ​* 
 * @return 0 : In case of faulty cased returning 0
*************************************************************************************************************************
*/

int test_hexdump()
{
   
    char str[1024];
    // Given test case from assignment
    const char buf[]= \
    {"To achieve great things, two things are needed:\n"
    "a plan, and not quite enough time."};
    

    const char exp_str[] = "0x0000  54 6F 20 61 63 68 69 65 \n" \
    "0x0008  76 65 20 67 72 65 61 74 \n" \
    "0x0010  20 74 68 69 6E 67 73 2C \n" \
    "0x0018  20 74 77 6F 20 74 68 69 \n" \
    "0x0020  6E 67 73 20 61 72 65 20 \n" \
    "0x0028  6E 65 65 64 65 64 3A 0A \n" \
    "0x0030  61 20 70 6C 61 6E 2C 20 \n" \
    "0x0038  61 6E 64 20 6E 6F 74 20 \n" \
    "0x0040  71 75 69 74 65 20 65 6E \n" \
    "0x0048  6F 75 67 68 20 74 69 6D \n" \
    "0x0050  65 2E 00 \n";
    
    char *act_str = hexdump(str, sizeof(str), buf, strlen(buf)+1);
    // Comparing actual string returned from logic function to the expected string.
    if(memcmp(str,exp_str,sizeof(exp_str)) == 0)
    {
        printf("Test passed\n");
    }
    else
    {
        printf("Test failed\n");
    }
    
    printf("Expected string: %s\n",exp_str);
    printf("Actual string: %s\n",act_str);
    for(int i = 0;str[i]!='\0';i++)
    {
        //Taking the actual result and comparing with the expected resuls and printing values to make debugging easier
        if(str[i] != exp_str[i])
        printf("%d,%x,%x\t",i,str[i],exp_str[i]);
    }
    return 1;




}



















