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
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define inf 0x3f3f3f3f
typedef long long ll;
set<int>s;
int n,k,a,x,m;
int f(int q)
{
    return (q+1)/(a+1);
}
int main()
{
    int ans=-1;
    scanf("%d%d%d",&n,&k,&a);
    scanf("%d",&m);
    int len=(n+1)/(a+1);
    s.insert(0);
    s.insert(n+1);
    int flag=0;
    if(len<k)
    {
        flag=1;
        ans=1;
    }
    for(int i=1; i<=m; i++)
    {
        scanf("%d",&x);
        if(flag) continue;
        auto it=s.upper_bound(x);
        auto it2=s.lower_bound(x);
        it2--;
        int a1=f((*it)-(*it2)-1);
        int a2=f((*it)-x-1);
        int a3=f(x-(*it2)-1);
        len=len-(a1-a2-a3);
        if(len<k)
        {
            flag=1;
            ans=i;
        }
        s.insert(x);
    }
    printf("%d\n",ans);
    return 0;
}
/*
14 3 3
5
4 5 6 12 1
*/
