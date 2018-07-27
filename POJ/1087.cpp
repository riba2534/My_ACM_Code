#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
const int N=600+20;
int g[N][N],pre[N];
bool vis[N];
int st,ed,p;
bool bfs(int s,int t)
{
    mem(pre,-1);
    mem(vis,false);
    queue<int>q;
    vis[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(int i=st; i<=ed; i++)
        {
            if(!vis[i]&&g[now][i]>0)
            {
                vis[i]=true;
                pre[i]=now;
                if(i==t)
                    return true;
                q.push(i);
            }
        }
    }
    return false;
}
int EK(int s,int t)
{
    int v,w,d,maxflow=0;
    while(bfs(s,t))
    {
        v=t;
        d=inf;
        while(v!=s)
        {
            w=pre[v];
            d=min(d,g[w][v]);
            v=w;
        }
        maxflow+=d;
        v=t;
        while(v!=s)
        {
            w=pre[v];
            g[w][v]-=d;
            g[v][w]+=d;
            v=w;
        }
    }
    return maxflow;
}

map<string,int>mp;

int main()
{
    string s1,s2;
    int n,m,k;
    while(cin>>n)
    {
        mem(g,0);
        mp.clear();
        int cnt=1;
        for(int i=1; i<=n; i++)
        {
            cin>>s1;
            mp[s1]=cnt++;
            g[mp[s1]][N-1]=1;//从源点建立一条到插座的边
        }
        cin>>m;
        for(int i=1; i<=m; i++)
        {
            cin>>s1>>s2;
            mp[s1]=cnt++;
            if(mp[s2]==0)
                mp[s2]=cnt++;
            g[mp[s1]][mp[s2]]=1;
            g[0][mp[s1]]=1;
        }
        st=0;
        ed=N-1;
        cin>>k;
        for(int i=1; i<=k; i++)
        {
            cin>>s1>>s2;
            if(mp[s1]==0)
                mp[s1]=cnt++;
            if(mp[s2]==0)
                mp[s2]=cnt++;
            g[mp[s1]][mp[s2]]=inf;
        }
        cout<<m-EK(st,ed)<<endl;
    }
    return 0;
}

