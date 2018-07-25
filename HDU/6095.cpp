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
#define N 300
#define ll long long
using namespace std;
int a[100200];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        int cnt=0;
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        sort(a,a+n,cmp);
        for(int i=0; i<n; i++)
        {
            cnt++;
            if(a[i]-a[i+1]>m)
                break;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
