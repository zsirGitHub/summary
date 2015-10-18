#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void thread_function(void *param)
{
    printf("this is a thread.\n");
}

int thread_test(void)
{
    pthread_t thread_id;
    int ret;

    ret = pthread_create(&thread_id, NULL, (void *)&thread_function, NULL);
    if(ret != 0) {
        printf("pthread_create fail\n");
        return -1;
    }
    
    /*wait thread exit.*/
    sleep(1);
        
}

int main(int argc, char *argv[])
{
    thread_test();

    return 0;
}
