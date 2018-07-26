 
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int pre[5000];
int num[5000];
//并查集的两种操作。。直接复制上去
int find(int x)
{
    int r=x;
    while(pre[r]!=r)
        r=pre[r];

    int i=x,j;
    while(pre[i]!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
void mix(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
        pre[fy]=fx;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mem(num,0);
        int m,n;
        scanf("%d%d",&m,&n);
        for(int i=1;i<=m;i++)pre[i]=i;//把每个元素的根节点置为自己
        int a,b;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            num[a]++;
            num[b]++;
            mix(a,b);
        }
        int cnt=0,ans=0;
        for(int i=1;i<=m;i++)//遍历所有顶点
        {
            if(pre[i]==i)
                cnt++;//计算根节点数量，如果节点数量大于1就证明某一个点不能被访问到
            if(num[i]&1)//计算奇顶点的个数
                ans++;
        }
        if(cnt==1&&(ans==0||ans==2))//先判断图的连通性，再判断奇顶点的个数是不是0或2
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
        