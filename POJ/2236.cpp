#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 1000+20
#define M 100000+20
#define MOD 1000000000+7
#define inf 0x3f3f3f3f
using namespace std;
struct node
{
    int x,y;
} p[N];//存储坐标
int f[N];//存储并查集的关系
int rep[N];//存储机器的编号
void init(int n)
{
    for(int i=1; i<=n; i++)
        f[i]=i;
}
int dist(node a,node b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int find(int x)
{
    if(f[x]!=x)
        f[x]=find(f[x]);
    return f[x];
}
void mix(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x!=y)
        f[y]=x;
}
int main()
{
    char ch[5];
    int n,d,x,y;
    scanf("%d%d",&n,&d);
    for(int i=1; i<=n; i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    int cnt=0;
    init(n);//初始化并查集
    while(~scanf("%s",ch))
    {
        if(ch[0]=='O')//修理机器
        {
            scanf("%d",&x);
            for(int i=0; i<cnt; i++)
                if(dist(p[rep[i]],p[x])<=d*d)//如果两台机器可以连接，就加入并查集
                    mix(rep[i],x);
            rep[cnt++]=x;//存储修好的编号
        }
        else//询问机器
        {
            scanf("%d%d",&x,&y);
            x=find(x);
            y=find(y);
            if(x==y)
                printf("SUCCESS\n");
            else
                printf("FAIL\n");
        }
    }
    return 0;
}
