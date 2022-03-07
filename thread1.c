#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#define n 26
#define m 26
char ch=65;
pthread_mutex_t lock;
void*cap(void*ptr)
{
        pthread_mutex_lock(&lock);
        for(int i=1;i<=n;i++)
        {
                sleep(1);
                printf("%c\n",ch);
                ch++;
        }
        ch=65;
        pthread_mutex_unlock(&lock);
}
void*sma(void*ptr1)
{
        pthread_mutex_lock(&lock);
        for(int i=1;i<=m;i++)
        {
                sleep(1);
                printf("%c\n",ch+32);
                ch++;
        }
        pthread_mutex_unlock(&lock);
}
int main()
{
        pthread_t tid[2];
        pthread_create(&tid[0],NULL,&cap,NULL);
        pthread_create(&tid[1],NULL,&sma,NULL);
        pthread_join(tid[0],NULL);
        pthread_join(tid[1],NULL);
}
