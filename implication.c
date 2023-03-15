#include <stdio.h>



int main()
{
    printf("Implication :\n");
    
    printf("%d\t%d\t%d\n", 1, 1, !1 || 1);
    printf("%d\t%d\t%d\n", 1, 0, !1 || 0);
    printf("%d\t%d\t%d\n", 0, 1, !0 || 1);
    printf("%d\t%d\t%d\n", 0, 0, !0 || 0);
    
    return 0;
}
