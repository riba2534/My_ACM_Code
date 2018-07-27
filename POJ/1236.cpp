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
const int N=200+20;
int DFN[N];//记录搜索到该点的时间
int LOW[N];//记录当前搜索的强连通子树的根节点
int Stack[N],Stop;//定义工作栈
int Dindex;//记录访问节点次序
int Bcnt;//强连通子图个数
int n,m;
bool instack[N];//标记是否在栈中
int color[N];
int in_deg[N],out_deg[N];
vector<int>e[N];

void tarjan(int i)
{
    DFN[i]=LOW[i]=++Dindex;
    instack[i]=true;//标记当前节点已经入栈
    Stack[++Stop]=i;//i入栈
    for(int k=0; k<(int)e[i].size(); k++)
    {
        int j=e[i][k];//找到邻接的顶点
        if(!DFN[j])//当该顶点没有被标记
        {
            tarjan(j);
            LOW[i]=min(LOW[i],LOW[j]);//更新一下子树的根节点
        }
        else if(instack[j]&&DFN[j]<LOW[i])//找到一个环
            LOW[i]=DFN[j];
    }
    if(DFN[i]==LOW[i])
    {
        Bcnt++;
        int top;
        do
        {
            top=Stack[Stop--];
            color[top]=Bcnt;
            instack[top]=false;
        }
        while(top!=i);
    }
}
void solve()
{
    mem(DFN,0);
    mem(LOW,0);
    mem(in_deg,0);
    mem(out_deg,0);
    mem(instack,0);
    Stop=Bcnt=Dindex=0;
    for(int i=1; i<=n; i++)
        if(!DFN[i])
            tarjan(i);
    if(Bcnt==1)
    {
        printf("1\n0\n");
        return;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<(int)e[i].size(); j++)
        {
            int v=e[i][j],u=i;
            if(color[u]==color[v])
                continue;
            out_deg[color[u]]++;
            in_deg[color[v]]++;
        }
    }
    int a=0,b=0;
    for(int i=1; i<=Bcnt; i++)
    {
        if(!in_deg[i])a++;
        else if(!out_deg[i])b++;
    }
    printf("%d\n%d\n",a,max(a,b));
}
int main()
{
    int x;
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
            while(scanf("%d",&x)&&x)
                e[i].push_back(x);
        solve();
    }
    return 0;
}


