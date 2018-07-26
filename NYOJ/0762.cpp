 
#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define inf 1000000
#define mem(a,b) memset(a,b,sizeof(a))
int a[50],b[1010];//a保存n的质因子,a[0]表示质因子个数
void div(int n)//分解质因数
{
    int j=0;
    for(int i=2; i*i<=n; i++)
        if(n%i==0)
        {
            while(n%i==0)
                n/=i;
            a[++j]=i;
        }
    if(n>1) a[++j]=n;
    a[0]=j;
}

int get_cnt(int mid)//1--mid之间与n互质的数有多少个
{
    int g=0,sum=mid,t;
    b[++g]=1;
    for(int i=1; i<=a[0]; i++)
    {
        t=g;
        for(int j=1; j<=g; j++)
        {
            b[++t]=b[j]*a[i]*-1;
            sum+=mid/b[t];
        }
        g=t;
    }
    return sum;
}

int erfen(int n,int k)
{
    int mid,l=1,r=(int)2e9;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(get_cnt(mid)<k)
            l=mid+1;
        else
            r=mid-1;
    }
    return l;
}

int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        div(n);
        printf("%d\n",erfen(n,k));
    }
    return 0;
}
        