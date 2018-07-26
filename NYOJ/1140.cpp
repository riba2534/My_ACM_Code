 
#include<stdio.h>
#include<string.h>

char s[10];
long long v[1001000];

int main()
{
    long long step;
    scanf("%lld",&step);
    while(step--)
    {
        long long n;
        scanf("%lld",&n);
        long long i,tail=0;
        for(i=0; i<n; i++)
        {
            scanf("%s",s);
            if(strcmp(s,"push")==0)
                scanf("%lld",&v[tail++]);
            else if(tail==0)
                continue;
            else tail--;
        }
        if(tail==0)
        {
            printf("no eggs!\n");
            continue;
        }
        for(i=--tail; i>0; i--)
            printf("%lld ",v[i]);
        printf("%lld\n",v[i]);
    }
    return 0;
}        