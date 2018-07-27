#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 100+20
#define M 100000+20
#define inf 0x3f3f3f3f
using namespace std;
map<string,int>mp;
double d[50][50];
int n,m;
int main()
{
    int q=1;
    while(~scanf("%d",&n)&&n)
    {
        char s1[50],s2[50];
        mp.clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s1);
            mp[s1]=i;
            d[i][i]=1;
        }
        scanf("%d",&m);
        double x;
        for(int i=1;i<=m;i++)
        {
            scanf("%s%lf%s",s1,&x,s2);
            d[mp[s1]][mp[s2]]=x;
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(d[i][j]<d[i][k]*d[k][j])
                        d[i][j]=d[i][k]*d[k][j];
        bool ok=false;
        for(int i=1;i<=n;i++)
            if(d[i][i]>1)
        {
            ok=true;
            break;
        }
        if(ok)
            printf("Case %d: Yes\n",q++);
        else
            printf("Case %d: No\n",q++);

    }
    return 0;
}
