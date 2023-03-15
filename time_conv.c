#include <stdio.h>



int main()
{
    printf("enter duration in seconds :\n");
    
    int duration;
    scanf("%d", &duration);
    
    int hours = duration / 3600;
    int minutes = (duration - hours * 3600) / 60;
    int seconds = (duration - hours * 3600 - minutes * 60);
    
    printf("%d:%d:%d\n", hours, minutes, seconds);
    
    return 0;
}
