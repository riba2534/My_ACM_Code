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
} p[N];//�洢����
int f[N];//�洢���鼯�Ĺ�ϵ
int rep[N];//�洢�����ı��
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
    init(n);//��ʼ�����鼯
    while(~scanf("%s",ch))
    {
        if(ch[0]=='O')//�������
        {
            scanf("%d",&x);
            for(int i=0; i<cnt; i++)
                if(dist(p[rep[i]],p[x])<=d*d)//�����̨�����������ӣ��ͼ��벢�鼯
                    mix(rep[i],x);
            rep[cnt++]=x;//�洢�޺õı��
        }
        else//ѯ�ʻ���
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
