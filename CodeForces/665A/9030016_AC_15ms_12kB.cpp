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
#define N 111111
#define M 1000000
#define ll long long
using namespace std;
struct node
{
    int l,r;
} zz[1000];
int main()
{
    int a,ta,b,tb,hh,mm;
    scanf("%d%d%d%d",&a,&ta,&b,&tb);
    scanf("%d:%d",&hh,&mm);
    int num=0;
    int st=5*60;
    int ed=23*60+59;

    while(st<=ed)
    {
        zz[num].l=st;
        zz[num].r=zz[num].l+tb;
        st+=b;
        num++;
    }
    int a_st=hh*60+mm;
    int a_ed=a_st+ta;
    int ans=0;
    for(int i=0; i<num; i++)
    {
        if(a_st<zz[i].r&&zz[i].l<a_ed)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}