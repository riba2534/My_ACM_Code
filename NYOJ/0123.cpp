 
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
#define N 1001000
#define M 1000000
#define ll long long
using namespace std;
int c[N];
int lowbit(int x)//用来维护树状数组,得到管辖区间
{
    return x&-x;
}
void add(int k,int num,int n)//给数组的第k位增加num个
{
    while(k<=n)
    {
        c[k]+=num;
        k+=lowbit(k);
    }
}
int sum(int n)//求要查询的区间的前n项和
{
    int sum=0;
    while(n>0)
    {
        sum+=c[n];
        n-=lowbit(n);
    }
    return sum;
}
int main()
{
    int t,m,a,b,c;
    char s[15];
    scanf("%d%d",&t,&m);
    while(t--)
    {
        scanf("%s",s);
        if(s[0]=='A')
        {
            scanf("%d%d%d",&a,&b,&c);
            add(a,c,m);
            add(b+1,-c,m);

        }
        else if(s[0]=='Q')
        {
            scanf("%d",&a);
            printf("%d\n",sum(a));
        }
    }
    return 0;
}
        