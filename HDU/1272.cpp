#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int M=100009;
int a,b;
int pre[M];
int bian,dingdian;//边和顶点的数量
bool huan;//是否存在环
bool vis[M];//标记顶点
void init()
{
    for(int i=0; i<M; i++)
        pre[i]=i,vis[i]=false;
    huan=false;
    bian=0;
    dingdian=0;
}
int find(int x)//找到一个集合父节点
{
    int r=x;
    while(pre[r]!=r)
        r=pre[r];

//    int i=x,j;
//    while(pre[i]!=r)//路径压缩,缩小寻找次数
//    {
//        j=pre[i];
//        pre[i]=r;
//        i=j;
//    }
    return r;
}
void mix(int x,int y)
{
    if(x==y)
        huan=true;
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
    {
        pre[fy]=fx;
        bian++;
    }
    else
        huan=true;

}
int main()
{
    while(1)
    {
        init();
        scanf("%d%d",&a,&b);
        if(!a&&!b)
        {
            printf("Yes\n");
            continue;
        }
        if(a==-1&&b==-1)return 0;
        vis[a]=1;
        vis[b]=1;
        mix(a,b);
        while(1)
        {
            scanf("%d%d",&a,&b);
            if(!a&&!b)break;
            vis[a]=1;
            vis[b]=1;
            mix(a,b);
        }
        for(int i=0; i<M; i++)
            if(vis[i])
                dingdian++;
        if(huan==false&&bian+1==dingdian)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

