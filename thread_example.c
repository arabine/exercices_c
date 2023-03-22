#include <threads.h>
#include <stdio.h>

int run(void *arg)
{
    printf("Time: %s\n", ctime(&(time_t){time(NULL)}));
    printf("Hello world of C11 threads.\n");
    thrd_sleep(&(struct timespec){.tv_sec=1}, NULL); // sleep 1 sec
    printf("Time: %s\n", ctime(&(time_t){time(NULL)}));
    

    return 0;
}

int main(int argc, const char *argv[])
{
    thrd_t thread;
    int result;

    thrd_create(&thread, run, NULL);

    thrd_join(thread, &result);

    printf("Thread return %d at the end\n", result);
} 
