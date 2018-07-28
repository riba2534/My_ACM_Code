#include<stdio.h>

int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b))
    {
        int ans=0;
        for(int i=a;i<=b;++i)
        {
            if(i&1)
                ++ans;
        }
        printf("%d\n",ans);
    }
}