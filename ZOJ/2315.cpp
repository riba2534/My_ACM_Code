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
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N 100+20
#define M 1000000+10
#define ll long long
using namespace std;
int vis[500010];//标记有没有分到钱
int a[500010];//记录每个人的上司
int b[500010];//记录谁拿了钱
int main()
{
    int t,n,x;
    cin>>t;
    while(t--)
    {
        mem(vis,0);
        mem(a,0);
        mem(b,0);
        int len=0;
        cin>>n;
        for(int i=2; i<=n; i++)
            cin>>a[i];
        for(int i=n; i>=2; i--)
        {
            int f=a[i];//这个人的上司
            if(vis[i]==0&&vis[f]==0)//当且仅当这个人得到钱和它的上司也没得到钱
            {
                b[len++]=i;//给这个人发钱
                vis[i]=1;
                vis[f]=1;//标记一下这个人和它的上司的位置
            }
        }
        cout<<len*1000<<endl;//输出获得的钱数
        sort(b,b+len);//进行升序排序，题目要求
        for(int i=0; i<len-1; i++)
            printf("%d ",b[i]);
        printf("%d\n",b[len-1]);//防止PE，错开输出
        if(t)puts("");
    }
    return 0;
}