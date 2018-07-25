#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b)&&(a||b))
    {
        int p=0;
        for(int i=0;i<=99;i++)
        {
            int k=a*100+i;
            if(k%b==0)
            {
                if(p)printf(" ");
                printf("%02d",i);
                p++;
            }
                
        }
        puts("");
    }
    return 0;
}
