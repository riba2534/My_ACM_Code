#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,x;
int p[10];
int main()
{
    int flag=1;
    p[1]=p[2]=1;
    p[3]=-1;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&x);
        if(p[x]==-1)flag=0;
        if(x==1)
        {
            p[2]=-p[2];
            p[3]=-p[3];
        }
        else if(x==2)
        {
            p[1]=-p[1];
            p[3]=-p[3];
        }
        else if(x==3)
        {
            p[1]=-p[1];
            p[2]=-p[2];
        }
    }
    if(flag)puts("YES");
    else puts("NO");
    return 0;
}
