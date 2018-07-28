#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 10000+20
#define mod 10007
#define M 1000000+10
#define LL long long
using namespace std;
int pre[3010],x,y;
void init()
{
    for(int i=1; i<=2010; i++)
        pre[i]=i;
}
int find(int x)
{
    int num=0;
    while(x!=pre[x])
    {
        x=pre[x];
        num++;
    }
    return num;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        init();
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&x,&y);
            pre[x]=y;
        }
        int a=find(1);
        int b=find(2);
        if(a>b)
            printf("You are my elder\n");
        else if(a<b)
            printf("You are my younger\n");
        else if(a==b)
            printf("You are my brother\n");
    }
    return 0;
}
