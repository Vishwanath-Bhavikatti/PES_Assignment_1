#include<stdio.h>

int int_to_hexchar(int num)
{
    if(num < 10)
    {
        return num + '0';
    }
    else
    {
        return num + '7';
    }
    
    
}