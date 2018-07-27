#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define maxnum 6010
#define inf 0x3f3f3f3f
using namespace std;
int dis[maxnum],u[maxnum],v[maxnum],w[maxnum];
int first[maxnum],next[maxnum],vis[maxnum];
void spfa()
{
    queue<int>q;
    vis[1]=1;
    q.push(1);
    while(!q.empty())
    {
        int now=q.front();
        vis[now]=0;
        q.pop();
        for(int k=first[now];k!=-1;k=next[k])
      //  while(k!=-1)
        {
            if(dis[u[k]]+w[k]<dis[v[k]])
            {
                dis[v[k]]=dis[u[k]]+w[k];
                if(vis[v[k]]==0)
                {
                    q.push(v[k]);
                    vis[v[k]]=1;
                }
            }
        //    k=next[k];
        }

    }
}
int main()
{
    int t,n;
    while(~scanf("%d%d",&t,&n))
    {
        mem(dis,inf);
        dis[1]=0;
        mem(vis,0);
        mem(first,-1);
        mem(next,-1);
        for(int i=1; i<=2*t; i+=2)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            u[i]=v[i+1]=a;
            u[i+1]=v[i]=b;
            w[i]=w[i+1]=c;
            next[i]=first[u[i]];
            next[i+1]=first[u[i+1]];
            first[u[i]]=i;
            first[u[i+1]]=i+1;
        }
        spfa();
        printf("%d\n",dis[n]);
    }
    return 0;
}
