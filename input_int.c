#include <stdio.h>


int main(int argc, char *argv[])
{
    int sum = 0;
    int number = 0;
    do {
        printf("Entrez un nombre, zéro pour quitter:\n");
        scanf("%d", &number);
        sum += number;
        fflush(stdin);
    } while(number != 0);
    
    printf("Sum: %d\n", sum);
}

 
