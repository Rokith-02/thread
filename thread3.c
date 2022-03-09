#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int sum=0;
pthread_mutex_t lock;
void*add(void*ptr)
{
        pthread_mutex_lock(&lock);
        for(int i=0;i<10;i++)
        {
                sleep(1);
                sum++;
                printf("%d\n",sum);
        }
        pthread_mutex_unlock(&lock);
}
void*sub(void*ptr)
{
        pthread_mutex_lock(&lock);
        for(int i=0;i<10;i++)
        {
        sum--;
        printf("%d\n",sum);
        sleep(1);
        }
        pthread_mutex_unock(&lock);
}
int main()
{
        pthread_t tid[2];
        pthread_create(&tid[0],NULL,&add,NULL);
        pthread_create(&tid[1],NULL,&sub,NULL);
        pthread_join(tid[0],NULL);
        pthread_join(tid[1],NULL);
}
