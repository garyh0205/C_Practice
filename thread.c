#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#define MAX 10

pthread_t thread[3];
pthread_mutex_t mut;

int number=0;

void *thread1()
{
    printf ("thread1 Begin\n");
    for (int i = 1; i <= MAX; i++)
    {
        pthread_mutex_lock(&mut);
        printf("thread1 enter : number = %d\n",number);
        number++;
        sleep(2);
        printf("thread1 end : number = %d\n",number);
        pthread_mutex_unlock(&mut);
        sleep(3);
    }
    printf("Thread1 End\n");
    pthread_exit(NULL);
}

void *thread2()
{
    printf("thread2 Begin\n");
    for (int i = 1; i <= MAX; i++)
    {
        pthread_mutex_lock(&mut);
        printf("thread2 enter : number = %d\n",number);
        number++;
        sleep(2);
        printf("thread2 end : number = %d\n",number);
        pthread_mutex_unlock(&mut);
        sleep(3);
    }
    printf("thread2 End\n");
    pthread_exit(NULL);
}

void *thread3()
{
    printf("thread3 Begin\n");
    for (int i = 1; i <= MAX; i++)
    {
        pthread_mutex_lock(&mut);
        printf("thread3 enter : number = %d\n",number);
        number++;
        sleep(2);
        printf("thread3 end : number = %d\n",number);
        pthread_mutex_unlock(&mut);
        sleep(3);
    }
    printf("thread3 End\n");
    pthread_exit(NULL);
}

void thread_create(void)
{
    int temp;
    memset(&thread, 0, sizeof(thread));
    /*Create Thread*/
    if((temp = pthread_create(&thread[0], NULL, thread1, NULL)) != 0)
        printf("Thread1 Failed\n");
    else
        printf("Thread1 Success\n");
    if((temp = pthread_create(&thread[1], NULL, thread2, NULL)) != 0)
        printf("Thread2 Failed\n");
    else
        printf("Thread2 Success\n");
    if((temp = pthread_create(&thread[2], NULL, thread3, NULL)) != 0)
        printf("Thread3 Failed\n");
    else 
        printf("Thread3 Success\n");
}

void thread_wait(void)
{
            /*Wait Thread End*/
            if(thread[0] !=0) {
                pthread_join(thread[0],NULL);
                printf("Thread1 End Joined\n");
            }
                    
            if(thread[1] !=0) {
                pthread_join(thread[1],NULL);
                printf("Thread2 End Joined\n");
            }

            if(thread[2] !=0) {
                pthread_join(thread[2],NULL);
                printf("Thread3 End Joined\n");
            }
}

int main()
{        
    pthread_mutex_init(&mut,NULL);
    printf("Main Thread\n");
    thread_create();
    printf("Main Thread : Wait for Thread End\n");
    thread_wait();
    return 0;
}
