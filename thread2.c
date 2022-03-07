#include<stdio.h>
#include<pthread.h>
#define max 10
pthread_t a[2];
pthread_mutex_t lock;
void*even(void *ptr)
{
        pthread_mutex_lock(&lock);
        a[0]=pthread_self();
        printf("%ld\n",a[0]);
        for(int i=1;i<=max;i++)
        {
                sleep(1);
                if(i%2==0)
                printf("even number: %d\n",i);
                //pthread_cancel(a[0]);
                //pthread_cancel(a[1]);
        }
        //pthread_mutex_lock(&lock);
}
void*odd(void *ptr1)
{
        a[1]=pthread_self();
        printf("%ld\n",a[1]);
        for(int i=1;i<=max;i++)
        {
                sleep(1);
                if((i%2)!=0)
                printf("odd number : %d\n",i);
        }
}
void main(void)
{
        pthread_t tid[2];
        pthread_create(&tid[0],NULL,&even,NULL);
        pthread_create(&tid[1],NULL,&odd,NULL);
        pthread_join(tid[0],NULL);
        pthread_join(tid[1],NULL);
}
