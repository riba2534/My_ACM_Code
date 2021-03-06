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
#define N 30000+50
#define M 100000+50
#define ll long long
using namespace std;
int n,m,len,k;
struct node
{
    int v,next;
} E[M];
int first[N],vis[N],path[N];
void add_edge(int u,int v)
{
    E[len].v=v;
    E[len].next=first[u];
    first[u]=len++;
}
void toposort()
{
    k=0;
    priority_queue<int>q;
    for(int i=1; i<=n; i++)
        if(!vis[i])
            q.push(i);//找出入度为0的顶点，放进优先队列
    while(!q.empty())
    {
        int u=q.top();
        q.pop();
        path[k++]=u;//记录顺序
        for(int i=first[u]; i!=-1; i=E[i].next)
        {
            int v=E[i].v;
            vis[v]--;//删除边
            if(!vis[v])
                q.push(v);//如果入度为0，继续删去
        }
    }
}
int main()
{
    int u,v,t;
    scanf("%d",&t);
    while(t--)
    {
        len=0;
        scanf("%d%d",&n,&m);
        mem(first,-1);
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&u,&v);
            add_edge(v,u);
            vis[u]++;//记录入度
        }
        toposort();
        for(int i=k-1; i>=0; i--)
        {
            printf("%d",path[i]);
            if(i)printf(" ");
        }
        puts("");
    }
    return 0;
}
