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
#define N 1000000+20
#define mod 10007
#define M 1000000+10
#define ll long long
using namespace std;
int vis[N];
struct node
{
    int a1,b2,c3,d4,e5,f6;
    int step;
} st,ed;
node fanzhuan(node now,int i)
{
    node to;
    if(i==0)//沿CG反转
    {
        to.a1=now.e5;
        to.b2=now.f6;
        to.c3=now.c3;
        to.d4=now.d4;
        to.e5=now.b2;
        to.f6=now.a1;

    }
    else if(i==1)//沿DH反转
    {
        to.a1=now.f6;
        to.b2=now.e5;
        to.c3=now.c3;
        to.d4=now.d4;
        to.e5=now.a1;
        to.f6=now.b2;

    }
    else if(i==2)//沿CD反转
    {
        to.a1=now.d4;
        to.b2=now.c3;
        to.c3=now.a1;
        to.d4=now.b2;
        to.e5=now.e5;
        to.f6=now.f6;

    }
    else if(i==3)//沿GH反转
    {
        to.a1=now.c3;
        to.b2=now.d4;
        to.c3=now.b2;
        to.d4=now.a1;
        to.e5=now.e5;
        to.f6=now.f6;
    }
    return to;
}
int add(node x)
{
    int temp=0;
    temp+=x.a1;
    temp+=x.b2*10;
    temp+=x.c3*100;
    temp+=x.d4*1000;
    temp+=x.e5*10000;
    temp+=x.f6*100000;
    return temp;
}
int bfs()
{
    node now;
    mem(vis,0);
    int p=add(st);//计算初始值和结束值
    int ans=add(ed);
    vis[p]=1;//标记
    now=st;
    now.step=0;
    queue<node>q;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if(add(now)==ans)//返回条件
            return now.step;
        for(int i=0; i<4; i++)
        {
            node t=fanzhuan(now,i);
            p=add(t);
            if(vis[p]==0)
            {
                t.step=now.step+1;
                q.push(t);
                vis[p]=1;
            }
        }
    }
    return -1;
}
int main()
{
    while(~scanf("%d%d%d%d%d%d",&st.a1,&st.b2,&st.c3,&st.d4,&st.e5,&st.f6))
    {
        scanf("%d%d%d%d%d%d",&ed.a1,&ed.b2,&ed.c3,&ed.d4,&ed.e5,&ed.f6);
        printf("%d\n",bfs());
    }
    return 0;
}
