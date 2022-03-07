#include<stdio.h>
int main()
{
        int a=4,b=8;
        int i,j,count=0,k,m;
        for(i=31;i>=0;i--)
        {
                if((a&1<<i)==0)
                continue;
                else
                break;
        }
        for(j=31;j>=0;j--)
        {
                if((b&1<<j)==0)
                continue;
                else
                break;
        }
        for(k=i;k>=0;k--)
        {
                if(a&(1<<k))
                printf("1");
                else
                printf("0");
        }
        printf("\n");
        for(m=j;m>=0;m--)
        {
                if(b&(1<<m))
                printf("1");
                else
                printf("0");
        }
        printf("\n");
        if(i<=j)
        j=i;
        else
	i=j;
        for(i=i,j=j;i>=0,j>=0;i--,j--)
        {
                if(((a&(1<<i))^(b&(1<<j)))==0)
                count++;
        }
        printf("equal bits are:%d\n",count);
}
