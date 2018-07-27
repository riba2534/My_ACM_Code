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
#define N 100000+20
#define mod 10007
#define M 1000000+10
#define LL long long
using namespace std;
int t,n,m,k,a,b;
vector<int>v[110];
set<int>s;
int vis[120][120];
int judge(int x,int y)
{
    s.clear();
    for(int i=0;i<v[x].size();i++)
        s.insert(v[x][i]);
    for(int i=0;i<v[y].size();i++)
        s.insert(v[y][i]);
    if(v[x].size()+v[y].size()-s.size()>=k)
        return 1;
    return 0;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        mem(vis,0);
        for(int i=0;i<110;i++)
        {
            vis[i][i]=1;
            v[i].clear();
        }
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
            vis[a][b]=vis[b][a]=1;
        }
        int sum=0;
        int flag=1;
        while(flag)
        {
            flag=0;
            for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(!vis[i][j])
                {
                    if(judge(i,j))
                    {
                        flag=1;
                        v[i].push_back(j);
                        v[j].push_back(i);
                        vis[i][j]=vis[j][i]=1;
                        sum++;
                    }

                }
            }
        }

        }

        printf("%d\n",sum);
    }
    return 0;
}