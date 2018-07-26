 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int n;
int sum,minn;
int a[10050];
int abss(int x)
{
    return x>0?x:-x;
}
void dfs(int s,int b)//s记录次数,b记录一个人分的西瓜的重量，i记录
{
    if(s==n)//当次数等于西瓜的个数
    {
        if(minn>abss(sum-2*b))
            minn=abss(sum-2*b);//更新最小值
        return;
    }
//    printf("i=%d\n",i);
    dfs(s+1,b+a[s]);//把西瓜分给其中一个人
    dfs(s+1,b);//把西瓜不分给其他一个人
    return;
}
int main()
{
    while(~scanf("%d",&n))
    {
        sum=0,minn=11111;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];//记录西瓜总重
        }
        dfs(0,0);
        printf("%d\n",minn);
    }
    return 0;
}
        