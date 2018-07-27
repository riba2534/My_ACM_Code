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
#define N 1000+20
#define mod 10007
#define M 1000000+10
#define LL long long
using namespace std;
int num1[N];
int num[N];//记录得票的数量
int vis[N];//标记是否被贿赂
struct node
{
    int v,w;
} g[N];
bool cmp(node a,node b)
{
    return a.w<b.w;
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        mem(num,0);
        mem(g,0);
        cin>>n;
        for(int i=1; i<n; i++)
        {
            cin>>g[i].v;
            num[g[i].v]++;//给对应的人记录票数
        }
        for(int i=1; i<n; i++)
        {
            cin>>g[i].w;
        }
        sort(g+1,g+n,cmp);
        int minn=inf;
        int sum;
        for(int i=num[1]; i<n; i++)
        {
            mem(vis,0);//所有人都没被贿赂
            memcpy(num1,num,sizeof(num));
            int flag_num=num1[1];
            sum=0;
            for(int j=1; j<n; j++)
            {
                if(g[j].v!=1&&num1[g[j].v]>=i)
                {
                    num1[g[j].v]--;
                    flag_num++;
                    vis[j]=1;
                    sum+=g[j].w;
                }
            }
            if(flag_num<=i)
            {
                for(int j=1; j<n&&flag_num<i; j++)
                {
                    if(vis[j]==0&&g[j].v!=1)
                    {
                        num1[g[j].v]--;
                        flag_num++;
                        vis[j]=1;
                        sum+=g[j].w;
                    }
                }
                int j=2;
                for(; j<=n&&num1[j]>=i; j++);
                if(j!=n+1)
                    minn=min(minn,sum);
            }
        }
        cout<<minn<<endl;
    }
    return 0;
}