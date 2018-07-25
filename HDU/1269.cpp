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
const int N=10000+20;
int DFN[N];//记录搜索到该点的时间
int LOW[N];//记录当前搜索的强连通子树的根节点
int Stack[N],Stop;//定义工作栈
int Dindex;//记录访问节点次序
int Bcnt;//强连通子图个数
int n,m;
bool instack[N];//标记是否在栈中
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
            instack[top]=false;
        }
        while(top!=i);
    }
}
int main()
{
    int a,b;
    while(scanf("%d%d",&n,&m)&&(n||m))
    {
        for(int i=0; i<=n; i++) e[i].clear();
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&a,&b);
            e[a].push_back(b);
        }
        Stop=Bcnt=Dindex=0;
        mem(DFN,0);
        for(int i=1; i<=n; i++)
            if(!DFN[i])
                tarjan(i);
        puts(Bcnt==1?"Yes":"No");
    }
    return 0;
}
