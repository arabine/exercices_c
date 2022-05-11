#include <stdio.h>
#include <stdlib.h>

/*
 Write a program that has the user enter three real numbers x, y, z and 
 sorts them in ascending order (at the end of the program execution: x ≤ y ≤ z).
 */


void print_help(const char *exe_name)
{
    printf("Sort three integers passed in parameters.\n\nUsage: %s value1 value2, value3\n\n", exe_name);
}


int main(int argc, char **argv)
{
    if (argc != 4)
    {
        print_help(argv[0]);
        return -1;
    }
    
    int value1 = atoi(argv[1]);
    int value2 = atoi(argv[2]);
    int value3 = atoi(argv[3]);
    
    if (value1 > value3)
    {
        // swap(a, c);
        int tmp = value1;
        value1 = value3;
        value3 = tmp;
    }
    
    if (value1 > value2)
    {
        // swap(a, b);
        int tmp = value1;
        value1 = value2;
        value2 = tmp;
    }

    //Now the smallest element is the 1st one. Just check the 2nd and 3rd
    if (value2 > value3)
    {
        // swap(b, c);
        int tmp = value2;
        value2 = value3;
        value3 = tmp;
    }

    printf("%d, %d, %d\n", value1, value2, value3);
    
    return 0;
}


