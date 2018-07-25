#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int a[15];
int vis[15],ans;
int abs(int x)
{
    if(x<0)
        return -x;
    return x;
}
void dfs(int step,int sum)//已经移动的牌和已经耗费的步数
{
    if(sum>=ans)return;//剪枝，当已经耗费的步数大于等于当前的最小步数就返回
    if(step==9)//10不用移动，只用移动9张
    {
        ans=sum;//更新ans的值
        return;
    }
    for(int i=1; i<10; i++)//从1-9开始枚举
    {
        if(!vis[i])//没有被标记过
        {
            vis[i]=1;//标记
            for(int j=i+1; j<=10; j++)//判断可以放到那张牌上
            {
                if(!vis[j])
                {
                    dfs(step+1,sum+abs(a[i]-a[j]));//搜索下一层，sum+牌i的位置-牌j位置的绝对值
                    break;
                }
            }
            vis[i]=0;//标记回来
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x;
        for(int i=1; i<=10; i++)
        {
            scanf("%d",&x);
            a[x]=i;//牌号为x的牌所在的位置
        }
        mem(vis,0);
        ans=100000;
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
