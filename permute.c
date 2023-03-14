#include <stdio.h>

/*
 
 Write a function taking as parameters three real variables x, y, z


Realize the circular permutation of these three variables: at the end of the function, x will contain the initial value of z, y will contain the initial value of x and z the initial value of y


 This function will not return any value
 
 */

void permute(float *x, float *y, float *z)
{
    float tmp_x = *x;
    float tmp_y = *y;
    
    *x = *z;
    *z = tmp_y;
    *y = tmp_x;
}

int main()
{
    float x = 3.14, y = 7.92, z = 10.01;
    
    printf("%.2f, %.2f, %.2f\n", x, y, z);
    
    permute(&x, &y, &z);
    
    printf("%.2f, %.2f, %.2f\n", x, y, z);
    
    int i = 2, j = 4;
    
    printf("Before: i=%d, j=%d\n", i, j);
    
    i = i + j;
    j = i - j;
    i = i - j;

    printf("After: i=%d, j=%d\n", i, j);
    
    return 0;
}
