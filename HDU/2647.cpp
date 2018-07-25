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
#define mod 1000007  
#define N 20100  
#define M 100000+50  
#define ll long long  
using namespace std;  
int n,m,len,k=0;  
int first[N],vis[N],path[N];  
struct node  
{  
    int u,v,next;  
}G[N];  
void add_edge(int u,int v)  
{  
    G[len].v=v;  
    G[len].next=first[u];  
    first[u]=len++;  
}  
void toposort()  
{  
    mem(path,0);  
    stack<int>s;  
    for(int i=1;i<=n;i++)  
        if(!vis[i])  
            s.push(i);  
    while(!s.empty())  
    {  
        int u=s.top();  
        s.pop();  
        for(int i=first[u];~i;i=G[i].next)  
        {  
            int v=G[i].v;  
            path[v]=max(path[v],path[u]+1);  
            vis[v]--;  
            if(!vis[v])  
                s.push(v);  
        }  
    }  
  
}  
int main()  
{  
    while(~scanf("%d%d",&n,&m))  
    {  
        len=1;  
        mem(first,-1);  
        mem(vis,0);  
        int x,y;  
        for(int i=1;i<=m;i++)  
        {  
            scanf("%d%d",&x,&y);  
            add_edge(y,x);  
            vis[x]++;  
        }  
        toposort();  
        int sum=0,flag=0;  
        for(int i=1;i<=n;i++)  
        {  
            if(vis[i])  
            {  
                flag=1;  
                break;  
            }  
            sum+=path[i];  
        }  
        if(flag)puts("-1");  
        else printf("%d\n",sum+888*n);  
    }  
    return 0;  
}