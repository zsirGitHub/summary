#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void thread_function(void *param)
{
    printf("this is a thread.\n");
    sleep(2);
    pthread_exit((void *)2);
}

int thread_test(void)
{
    pthread_t thread_id;
    int ret;
    int *retval;

    ret = pthread_create(&thread_id, NULL, (void *)&thread_function, NULL);
    if(ret != 0) {
        printf("pthread_create fail\n");
        return -1;
    }

    ret = pthread_join(thread_id, (void *)&retval);
    if(ret != 0) {
        printf("pthread_join fail\n");
        return -1;
    }

    printf("thread return value is %d\n", retval);
}

int main(int argc, char *argv[])
{
    thread_test();

    return 0;
}
