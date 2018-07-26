 
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
#define inf 0x3f3f3f3f
const int N=1e6+10;
int n,m;
int c[N];
int lowbit(int x)
{
    return x&-x;
}
void add(int i,int k)
{
    while(i<=n)
    {
        c[i]+=k;
        i+=lowbit(i);
    }
}
int query(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=c[i];
        i-=lowbit(i);
    }
    return sum;
}
int main()
{
    int x,a,b;
    char s[5];
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        add(i,x);
    }
    while(m--)
    {
        scanf("%s%d%d",s,&a,&b);
        if(s[0]=='Q')
            printf("%d\n",query(b)-query(a-1));
        else
            add(a,b);
    }
    return 0;
}
        