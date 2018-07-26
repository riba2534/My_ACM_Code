 
#include<stdio.h>
#include<cmath>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int t,ceng=0;//m为梦境层数
        int time=0;
        scanf("%d",&t);
        while(t--)
        {
            char p[5];
            scanf("%s",p);
            if(p[0]=='I')
                ++ceng;
            else if(p[0]=='S')
            {
                int p;
                scanf("%d",&p);
                time+=p/(double)pow(20,ceng)*60;
            }
            else
                --ceng;
        }
        printf("%d\n",time);

    }
    return 0;
}
        