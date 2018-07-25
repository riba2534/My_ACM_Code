#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 10000+20
#define M 2000+10
#define LL long long
using namespace std;
struct node
{
    int num,start,end;
} zz[N];//记录凳子的数量，开始和结束的时间
int sum[N];
bool cmp(node a,node b)
{
    if(a.start==b.start)
        return a.end<b.end;
    else
        return a.start<b.start;//按照开始时间从前到后排序
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mem(sum,0);
        int n;
        scanf("%d",&n);
        int num,a1,a2,b1,b2;
        for(int i=0; i<n; i++)
        {
            scanf("%d %d:%d %d:%d",&num,&a1,&a2,&b1,&b2);
            zz[i].num=num;
            zz[i].start=a1*100+a2;//把时间转换成容易表示的值
            zz[i].end=b1*100+b2;
            for(int j=zz[i].start; j<zz[i].end; j++)
                sum[j]+=zz[i].num;
        }
        int maxx=0;
        for(int i=0; i<=M; i++)
            maxx=max(sum[i],maxx);//找出里面最大的
        printf("%d\n",maxx);
    }
    return 0;
}