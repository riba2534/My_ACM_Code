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
const int N=16000+10;
int b[N];
int vis[N],ans[N];
struct node
{
    int x,id;
} a[N];
struct hpc
{
    inline bool operator()(const node& t1,const node& t2)
    {
        return t1.x<t2.x;
    }
};
int main()
{
    int n;
    mem(b,-1);
    mem(ans,0);
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i].x);
        a[i].id=i;
    }
    sort(a+1,a+n+1,hpc());
    for(int i=1; i<=n; i++)
    {
        mem(vis,0);
        int id=a[i].id;
        b[id]=0;
        int sum=8000;
        vis[8000]=1;
        for(int j=1; j<id; j++)
        {
            sum+=b[j];
            vis[sum]++;
        }
        for(int j=id; j<=n; j++)
        {
            sum+=b[j];
            if(vis[sum])
            {
                ans[id]+=vis[sum];
            }
        }
        b[id]=1;
    }
    for(int i=1; i<=n; i++)
    {
        printf("%d ",ans[i]);
    }
    puts("");
    return 0;
}
/*
13
5 8 7 11 2 13 3 6 12 9 4 1 10
*/
