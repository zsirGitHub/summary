#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_t thread1_id, thread2_id;

void thread_function1(void *param)
{
    printf("this is a thread 2.\n");
    while(1) {
        printf("thread 1 is running.\n");
        sleep(1);
    }

    printf("thread 1 exit.\n");
}

void thread_function2(void *param)
{
    printf("this is a thread 2.\n");
    sleep(2);
    printf("thread 2 cancel thread 1.\n");
    pthread_cancel(thread1_id);
}

int thread_test(void)
{
    int ret;

    ret = pthread_create(&thread1_id, NULL, (void *)&thread_function1, NULL);
    if(ret != 0) {
        printf("pthread_create fail\n");
        return -1;
    }

    ret = pthread_create(&thread1_id, NULL, (void *)&thread_function2, NULL);
    if(ret != 0) {
        printf("pthread_create fail\n");
        return -1;
    }

    ret = pthread_join(thread1_id, NULL);
    if(ret != 0) {
        printf("pthread_join fail\n");
        return -1;
    }
}

int main(int argc, char *argv[])
{
    thread_test();

    return 0;
}
