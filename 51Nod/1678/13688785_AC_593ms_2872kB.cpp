#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include<list>
using namespace std;
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
const int N=1e5+10;
int n,q,tot;
int num[N],sum[N];
vector<int>v;
void init()
{
    for(int i=1; i<=n; i++)
        for(int j=1; i*j<=n; j++)
            sum[i]+=num[i*j];
}
void update(int x,int y)
{
    tot-=num[x];
    for(int i=1; i*i<=x; i++)
    {
        if(x%i==0)
        {
            if(i*i!=x)
            {
                sum[x/i]+=y-num[x];
            }
            sum[i]+=y-num[x];
        }
    }
    num[x]=y;
    tot+=num[x];
}
void get_prime(int x)
{
    v.clear();
    for(int i=2; i*i<=x; i++)
    {
        if(x%i==0)
        {
            v.push_back(i);
            while(x%i==0)x/=i;
        }
    }
    if(x>1)v.push_back(x);
}
int query(int x)
{
    get_prime(x);
    int res=0,len=v.size();
    for(int i=1; i<(1<<len); i++)
    {
        int cnt=0,t=1;
        for(int j=0; j<len; j++)
        {
            if(i&(1<<j))
            {
                t*=v[j];
                cnt++;
            }
        }
        if(cnt&1)
            res+=sum[t];
        else
            res-=sum[t];
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&num[i]);
        tot+=num[i];
    }
    init();
    int op,x,y;
    while(q--)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d",&x,&y);
            update(x,y);
        }
        else
        {
            scanf("%d",&x);
            printf("%d\n",tot-query(x));
        }
    }
    return 0;
}
