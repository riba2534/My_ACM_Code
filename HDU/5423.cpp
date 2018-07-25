#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10007
#define N 1000+20
#define M 1000000+10
#define ll long long
using namespace std;
vector<int>q[N];
int flag=0;
void dfs(int x,int op)
{
    if(flag||!q[x].size())
        return;
    if(op&&q[x].size()>0)
    {
        flag=1;
        return;
    }
    if(q[x].size()>1)//当儿子数大于1时
    {
        for(int i=0; i<q[x].size(); i++)
        {
            dfs(q[x][i],1);
        }
    }
    else
        dfs(q[x][0],0);
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        flag=0;
        for(int i=1; i<=n; i++)
            q[i].clear();
        int u,v;
        for(int i=0; i<n-1; i++)
        {
            scanf("%d%d",&u,&v);
            q[u].push_back(v);
        }
        dfs(1,0);
        if(flag)
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}
