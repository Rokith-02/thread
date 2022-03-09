#include<stdio.h>
void fun(char*a,char*b)
{
        int i,j,k;
        for(i=0;a[i];i++)
        {
        for(k=0;k<i;k++)
        {
                if(a[i]==a[k])
                break;
        }
        if(i==k)
        {
        for(j=0;b[j];j++)
        {
                if((a[i]=='a')||(a[i]=='e')||(a[i]=='o')||(a[i]=='i')||(a[i]=='u'))
                {
                        if(a[i]==b[j])
                        {
                                printf("%c ",a[i]);
                                break;
                        }
                }
        }
        }
        }
}
int main()
{
        char a[20],b[20];
        printf("enter the strings s1,s2\n");
        scanf("%s %s",a,b);
        void (*fp)(char*a,char*b);
        fp=fun;
        fp(a,b);
}
