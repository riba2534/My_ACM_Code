 
#include<stdio.h>
int main()
{
    int n,m,p,s;
    while (scanf("%d%d%d",&n,&m,&p)!=EOF)
    {

        s=1;
        for(int i=0; i<p; i++)
        {

            s=s*m;
            s%=7;
        }
       // printf("s=%d\n",s);
        s=s%7;
        //printf("s=%d\n",s);

        if((n+s)%7==0)
        {

            printf("7\n");
        }
        else
            printf("%d\n",(s+n)%7);
    }
}        