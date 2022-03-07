#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
        int roll;
}st;
void fun(st*a)
{
        for(int i=0;i<5;i++)
        printf("%d ",(a+i)->roll);
}
int main()
{
        int i;
        st*temp=(st*)malloc(5*sizeof(st));
        for(i=0;i<5;i++)
        scanf(" %d",&temp[i].roll);
        fun(temp);
}
