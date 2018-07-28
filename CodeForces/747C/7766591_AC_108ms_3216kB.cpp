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
struct nnd
{
    int start;//开始时间
    int num;//所需服务器数量
    int need;//需要用服务器的时间
} a[100005];
int vis[101];//用来标记当前时间这个服务器有没有被使用（使用服务器的最后时间）
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);//输入服务器数量和询问次数
    mem(vis,0);
    for(int i=0; i<q; i++)
        scanf("%d%d%d",&a[i].start,&a[i].num,&a[i].need);//读入数据
    for(int i=0; i<q; i++)//遍历询问次数
    {
        int knum=0;//标记服务器数量
        for(int j=1; j<=n&&knum<a[i].num; j++)//分配服务器
            if(vis[j]<a[i].start)//判断当前时间服务器有没有被使用
                knum++;
        if(knum==a[i].num)//如果把服务器的数量足够
        {
            long long sum=0;//计算编号和
            for(int j=1;j<=n&&knum>0;j++)
            {
                if(vis[j]<a[i].start)//当前服务器可以使用时
                {
                    vis[j]=a[i].start+a[i].need-1;//开始的时间加上需要的时间
                    knum--;
                    sum+=j;//累加
                }
            }
            printf("%lld\n",sum);//输出编号和
        }
        else
            printf("-1\n");
    }
    return 0;
}
