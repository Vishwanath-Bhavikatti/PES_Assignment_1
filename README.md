# Course : Principle of Embedded Software - ECEN 5813 (Spring 2023)
# Assignment_1
# Author : Vishwanath Bhavikatti
# Date : 1/24/2023


# The assignment gives some challenges to refresh C Skills and gain familarity with logical btwise operations

#Logic Functions :
### int binstr_to_uint(const char *str)
The function converts a given binary string to unsigned Integer in decimal format and returns a decimal integer.

### int int_to_binstr(char *str, size_t size, int32_t num, uint8_t nbits)
The function converts signed integer to binary string and returns the length of a string including 0b a binary reprsentation

### int hexstr_to_uint(const char *str)
The function returns a decimal unsigned integer for a given constant hexadecimal string
The hex string will be of the form ‘0xcccccc’ where ‘c’ must be between ‘0’ and ‘F’.  The casing of the characters in the 
string should not matter and it will handle ‘0x0F’ same as ‘0X0f’.

### uint32_t twiggle_except_bit(uint32_t input, int bit, operation_t operation)
The function Changes all bits of the input value except the given bit. Upon invocation, bit is in the range 0 to 31, inclusive. Returns 0xFFFFFFFF in the case of an error.

### uint32_t grab_four_bits(uint32_t input, int start_bit)
The function returns four bits from the input value, shifted down starting from start bit.

### char *hexdump(char *str, size_t size, const void *loc, size_t nbytes)
The function returns a string representing a “dump” of the nbytes of memory starting at loc. Bytes are printed up to 8 bytes per line, separated by newlines.


# Test Functions
Test case function are written in a seperate file to check all the known possible corner cases and the functions returns the status of test as Passed / Failed with number 
of test cases passed out of total test cases.
These test functions call the logic functions to verify the cases.

#Main.c
Main.c includes att the test files headers and prints the status as Passes in case every given test case is passed or it prints test cases failed.

##############################################################################################################################################################################

