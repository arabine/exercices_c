#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
/*
Write an algorithm that computes the minimum and the maximum of a given array of reals by doing only one iteration.
 */

void print_help(const char *exe_name)
{
    printf("Generate an array of real and find the min/max.\n\nUsage: %s array_size\n\n", exe_name);
}


int main(int argc, char **argv)
{
    srand(time(NULL));   // Initialization, should only be called once.

    if (argc != 2)
    {
        print_help(argv[0]);
        return -1;
    }
    
    int array_size = atoi(argv[1]);
    
    
    
    // Initialisation du tableau avec des valeurs aléatoires
    float tab[array_size];
    
    float min = 100.0;
    float max = 0.0;
    for (int i = 0; i < array_size; i++)
    {
        // création de la valeur aléatoire en entier puis conversion en float
        float r = rand() % 10000;
        tab[i] = r / 100;
        
        printf("%d => %.2f\n", i, tab[i]);
        
        if (tab[i] < min)
        {
            min = tab[i];
        }
        
        if (tab[i] > max)
        {
            max = tab[i];
        }
    }
    
    printf("Min: %.2f, Max: %.2f\n", min, max);
    
    return 0;
}


