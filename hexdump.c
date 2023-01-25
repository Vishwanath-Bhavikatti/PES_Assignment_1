#include<stdio.h>
#include<stdint.h>
#include<stddef.h>
//Including hexchar header file as the function is being used in this file
#include "int_to_hexchar.h"
#define line_length 8  // defines a length of line

/*
*********************************************************************************************************************
​ *
​ ​*​ ​Author​ :​Vishwanath Bhavikatti
 * @Credits : https://stackoverflow.com/questions/7775991/how-to-get-hexdump-of-a-structure-data
              http://web.cecs.pdx.edu/~harry/Blitz/BlitzSrc/hexdump.c
​ ​*​ ​@date​ :January 23, 2023 
 * @function name : hexdump.c
 * @Function_description:  Given a string, the function returns a hexadecimal values of each character 
 *                         in a string in a hex dump form
​ ​* @param char *str: string which has nbytes of memory to represent hexdump values
 * @param size_t size: size of a string
 * @param const void *loc: pointer pointing to a starting address of a string
 * @param size_t nbytes: Input string size  
​ ​*​ ​@return : The function returns a string which contains hex dump of an input 
 *           string with offset values at the beginning of a line
 * @return -1 : In case of faulty cased returning -1 
*************************************************************************************************************************
*/
char *hexdump(char *str, size_t size, const void *loc, size_t nbytes)
{
    //checking if string is null, returning NULL
    if(str == NULL)
    {
        return NULL;
    }
    char *s = str;
    const uint8_t *buf = (const uint8_t*)loc;
    
    *s= '\0';  // Initialising string as NULL

    // As each line requires 6 characters for offset, 2 space character and a new line character
    // each charcter in a input string requires 3 output bytes and at the end a null character
    // Hence checking whether the size is capable of holding rewuired space, if not returning NULL string 
    size_t str_size = ((nbytes/line_length) * 9) + (nbytes * 3) + 1;
    if(size < str_size)
    {
        return str;
    }

    // Limiting the output to 65535 bytes, in case of greater value returning NULL string
    if(nbytes > 0xFFFF)
    {
        return str;
    }
    
    for(int i = 0; (size_t)i < nbytes; i=i+line_length)
    {
        //Logic to print offset
        *s++ = '0';
        *s++ = 'x';
        *s++ = int_to_hexchar((i & 0xF000) >> 12);
        *s++ = int_to_hexchar((i & 0x0F00) >> 8);
        *s++ = int_to_hexchar((i & 0x00F0) >> 4);
        *s++ = int_to_hexchar(i & 0x000F);
        *s++ = ' ';
        *s++ = ' ';
        for(int j = 0;j < line_length && (size_t)(i+j) < nbytes; j++)
        {
            //Decimal ascii value of each character in string is converted to hexadecimal form 
            *s++ = int_to_hexchar((buf[i+j] & 0xf0) >> 4); //taking MSB Four bits 
            *s++ = int_to_hexchar(buf[i+j] & 0x0f);//taking LSB four bits
            *s++ = ' '; // adding a space between character
        }
        *s++ ='\n'; // adding newline character afer each line
        
    }
    *s++ = '\0';
    return str;
}