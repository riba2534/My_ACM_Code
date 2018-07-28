#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pir pair<int,int>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
const int N=2e6+20;
struct node
{
    int num,flag;
} a[N];
bool cmp(node a,node b)
{
    if(a.num==b.num)
        return a.flag>b.flag;
    else
        return a.num<b.num;
}
int ans[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k,tot=0,st,ed;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>st>>ed;
        a[tot].num=st;
        a[tot++].flag=1;
        a[tot].num=ed;
        a[tot++].flag=0;
    }
    sort(a,a+tot,cmp);
    int hpc=0,cnt=0;
    for(int i=0; i<tot; i++)
    {
        if(a[i].flag)
        {
            cnt++;
            if(cnt==k)
                ans[hpc++]=a[i].num;
        }
        else
        {
            if(cnt==k)
                ans[hpc++]=a[i].num;
            cnt--;
        }
    }
    cout<<hpc/2<<endl;
    for(int i=0; i<hpc; i+=2)
        printf("%d %d\n",ans[i],ans[i+1]);
    return 0;
}
