 
#include <stdio.h>
#include <math.h>
#include <string.h>
int sushu(int n)
{
    int flag,i;
    flag=1;
    if(n==0||n==1)
        flag=0;
    for( i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            flag=0;
            break;
        }
    }
    return flag;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char a[101];
        int b[1000];
        memset(b,0,sizeof(b));
        scanf("%s",a);
        int maxn=0,minn=100,len=strlen(a);
        for(int i=0; i<len; i++)
        {
            b[a[i]]++;
        }
        for(int i=0; i<len; i++)
        {
            if(b[a[i]]>=maxn)
                maxn=b[a[i]];
            if(b[a[i]]<=minn)
                minn=b[a[i]];
        }
       // printf("maxn=%d,minn=%d\n",maxn,minn);
       int s=maxn-minn;
       if(sushu(s)==1)
        printf("Lucky Word\n%d\n",s);
       else
        printf("No Answer\n0\n");


    }
    return 0;
}
        