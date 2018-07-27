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
int DFN[N];//��¼�������õ��ʱ��
int LOW[N];//��¼��ǰ������ǿ��ͨ�����ĸ��ڵ�
int Stack[N],Stop;//���幤��ջ
int Dindex;//��¼���ʽڵ����
int Bcnt;//ǿ��ͨ��ͼ����
int n,m;
bool instack[N];//����Ƿ���ջ��
int color[N];
int in_deg[N],out_deg[N];
vector<int>e[N];

void tarjan(int i)
{
    DFN[i]=LOW[i]=++Dindex;
    instack[i]=true;//��ǵ�ǰ�ڵ��Ѿ���ջ
    Stack[++Stop]=i;//i��ջ
    for(int k=0; k<(int)e[i].size(); k++)
    {
        int j=e[i][k];//�ҵ��ڽӵĶ���
        if(!DFN[j])//���ö���û�б����
        {
            tarjan(j);
            LOW[i]=min(LOW[i],LOW[j]);//����һ�������ĸ��ڵ�
        }
        else if(instack[j]&&DFN[j]<LOW[i])//�ҵ�һ����
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


