/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>



void test_password(char *tab, int idx, int size)
{
    for (char c = 'a'; c <= 'z'; c++)
    {
        tab[idx] = c;
        
        if (idx == (size-1))
        {
            printf("%s\n", tab);
            
        }
        else
        {
            idx++;
            test_password(tab, idx, 8);
            idx--;
        }
    }
    
}

int main()
{
    char password[9] = "00000000";
    
    test_password(password, 0, 8);

    return 0;
}
