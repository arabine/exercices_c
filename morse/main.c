
#include <stdio.h>
#include "morse.h"

void print_help(const char *exe_name)
{
    printf("Ouputs morse code translation from an input string passed as an argument (mandatory).\n\nUsage: %s \"your text, delimited by quotes.\"\n\n", exe_name);
}



int main(int argc, char **argv)
{
    if (argc != 2)
    {
        print_help(argv[0]);
        return -1;
    }
    
    printf("Entered: %s\n", argv[1]); 

    char output[MAX_OUTPUT_STRING];
    
    encode(argv[1], output);
    
    printf("Output: %s\n", output); 
    
}


