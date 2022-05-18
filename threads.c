#include <threads.h>
#include <stdio.h>
#include <unistd.h>

int cpt = 0;

int run(void *arg)
{
    cpt++;
    sleep(3);
    printf("Thread %d finished.\n", cpt);
    
    
    if (cpt < 10)
    {
        thrd_t thread;
        
        
        int result;
        thrd_create(&thread, run, NULL);

        thrd_join(thread, &result);
    }
    
    
    return 0;
}


int main()
{
    thrd_t thread;
    int result;

    thrd_create(&thread, run, NULL);

    thrd_join(thread, &result);

    printf("Thread return %d at the end\n", result);
    
    return 0;
}


