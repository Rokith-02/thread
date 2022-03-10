#include<stdio.h>
//void fun(int a,int b){ printf("rokith\n");}
/*int c;
int* fun(int*a,int*b)
{
        c=*a + *b;
        return &c;
}*/
char*fun(char*a)
{
        for(int i=0;i<5;i++)
        scanf(" %c",&a[i]);
        return a;
}
int main()
{
        /*void (*f[10])(int a,int b)={fun};
        f[0](10,20);*/
        /*int c=10,b=20;
        int*(*a[5])(int*a,int*b)={fun};
        int*p=a[0](&c,&b);
        printf("%d\n",*p);*/
        char a[5];
        char*(*x[3])(char*)={fun};
        char*p=x[0](a);
        for(int i=0;i<5;i++)
        printf("%c ",*(p+i));
}
