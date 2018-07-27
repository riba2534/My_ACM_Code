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
using namespace std;
const int N=1000+20;
int n,m;
bool vis[N];
int e[N][N],match[N][N];//match[][]
int num[N];// max_num --->right
bool dfs(int u)
{
    for(int v=0; v<m; v++)
    {
        if(e[u][v]&&!vis[v])
        {
            vis[v]=true;
            if(match[v][0]<num[v])
            {
                match[v][++match[v][0]]=u;
                return true;
            }
            for(int i=1; i<=num[0]; i++)
            {
                if(dfs(match[v][i]))
                {
                    match[v][i]=u;
                    return true;
                }
            }
        }
    }
    return false;
}
int query()
{
    mem(match,0);
    int sum=0;
    for(int i=0; i<n; i++)
    {
        mem(vis,0);
        if(dfs(i))sum++;
    }
    return sum;
}
bool judge(int mid)
{
    fill(num,num+n,mid);
    int ans=query();
    if(ans==n)
        return true;
    else
        return false;
}
int main()
{
    string s;
    int x;
    while(scanf("%d%d",&n,&m)&&(n||m))
    {
        mem(e,0);
        for(int i=0; i<n; i++)
        {
            cin>>s;
            while(getchar()!='\n')
            {
                scanf("%d",&x);
                e[i][x]=1;
            }
        }
        int l=0,r=n;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(judge(mid))
                r=mid;
            else
                l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}

