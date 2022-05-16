#include <stdio.h>
#include <stdlib.h>

// En C, on peut omettre la première dimension à un tableau passé en paramètre. Le nombre de lignes ne seront pas connues
// Par contre, toutes les dimensions suivantes doivent être indiquées


/*

   ptr_int     ptr_int     ptr_int  ...

   ptr_int

     ...

*/
void f1(int *app[][4]) // Un tableau en deux dimensions de pointeurs d'entiers
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%p ", app[i][j]); // obligé d'imprimer un type pointeur (addresse du int)
        }
    }
    printf("\n");
}


// La première dimension peut être omise, pas les autres dimensions !
void f2(int app[][4]) // un pointeur vers un tableau de 4 entiers
{
    printf("------------------------  f2  ---------------------------\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%p\n", app[i]);
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", app[i][j]);
        }
    }
    printf("\n");
}

void f3(int (*app)[4]) // un pointeur vers un tableau de 4 entiers
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("\t\t%p\n", &app[i][j]);
        }
    }
    printf("\n");
}


/*
   Un pointeur vers un pointeur d'entier

   *app est un pointeur, il pointe vers un emplacement en mémoire qui est
   lui-même un pointeur vers notre variable de type entier en mémoire (ici 4)


     app    --->    ptr_int    --->    4

*/
void f4(int **app) // pointeur vers un pointeur d'entier
{
    printf("------------------------  f4  ---------------------------\n");


    for (int i = 0; i < 4; i++)
    {
        printf("Row %d: %p\n", i, &app[i]);
        for (int j = 0; j < 4; j++)
        {
            printf("\t\t%p --> %d\n", &app[i][j], app[i][j]);
        }
    }
}


// Le tableau étant transformé en pointeur
// on a perdu la taille
// équivalent : int tab[]
void passage_tab1(int *tab)
{
    printf("Valeur index %d  --> %d\n", 4, tab[4]);
}

void passage_tab2(int tab[])
{
    printf("Valeur index %d  --> %d\n", 4, tab[4]);
}

void passage_tab3(int tab[10])
{
    printf("Valeur index %d  --> %d\n", 4, tab[4]);
}


int main(void)
{
    printf("==============================   Tableau 1D en variable locale  (stack)  ========================================\n");

    // un tableau de 10 cases d’entiers
    int tableau[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // in pointeur vers le premier élément du tableau
    int *pt = &tableau[0];

    printf("Taille du tableau %zd\n", sizeof(tableau));
    printf("Taille du pointeur %zd\n", sizeof(pt));

    passage_tab1(tableau);
    passage_tab2(tableau);
    passage_tab3(tableau);

    printf("==============================   Tableau 2D en variable locale  (stack)  ========================================\n");

    int array[4][4];
    int *array2[4][4];

    int *ptr = NULL;
    printf("Size of pointer: %lu\n", sizeof(ptr));


    printf("array   -->   %p\n", array); // donne l'adresse du premier élément du tableau
    printf("&array   -->   %p\n", &array);
    printf("sizeof(array)   -->   %lu\n", sizeof(array));
    for (int i = 0; i < 4; i++)
    {
        printf("\tarray[i]   -->    %p\n", array[i]);

        for (int j = 0; j < 4; j++)
        {
            array[i][j] = i * 4 + j;
            array2[i][j] = NULL;

            printf("\t\t%p --> array[%d][%d] : %d\n", &array[i][j], i, j, array[i][j]);
        }
    }

    f1(array2);
    f2(array);
    f3(array);


    printf("==============================   Tableau dans le tas  ========================================\n");
    int **x;

    // On réserve le conteneur des colonnes
    x = malloc(4 * sizeof *x);

    printf("x   -->   %p\n", &x); // donne l'adresse du premier élément du tableau

    // Pour chaque ligne, on réserve N colonnes
    for (int i = 0; i < 4; i++)
    {
        x[i] = malloc(4 * sizeof *x[i]);

        // init de la ligne
        for (int j = 0; j < 4; j++)
        {
            x[i][j] = i * 4 + j;
        }
    }

    f4(x);

    // libération de la mémoire
    for (int i=0; i<4; i++)
    {
            free(x[i]);
    }
    free(x);

    return 0;
}

