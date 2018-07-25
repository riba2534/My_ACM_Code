#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 100200
#define ll long long
using namespace std;
int maxx[N][20];
int a[N];
void RMQ(int n)
{
    for(int j=1; j<20; j++)
        for(int i=1; i<=n; i++)
            if(i+(1<<j)-1<=n)
            {
                maxx[i][j]=max(maxx[i][j-1],maxx[i+(1<<(j-1))][j-1]);
            }
}
int main()
{
    int t,n,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&x);
            maxx[i][0]=x;
        }
        RMQ(n);
        for(int i=2; i<=n; i++) //枚举间隔
        {
            int num=0;
            for(int j=1; j<=n; j+=i) //左端点
            {
                int p=j+i-2;//右端点
                if(p>n) p=n;
                if(p==j)
                    num=max(maxx[j][0],num);
                else
                {
                    int k=(int)(log(p-j+1.0)/log(2.0));
                    num=max(num,max(maxx[j][k],maxx[p-(1<<k)+1][k]));
                }
            }
            a[i]=num;
        }
        for(int i=2;i<=n;i++)
        {
            if(i>2)printf(" ");
            printf("%d",a[i]);
        }
        puts("");
    }
    return 0;
}













