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
#define mod 1000007
#define ll long long
using namespace std;
const int N=125250+10;
int a[N];
int f[400];
int main()
{
    int m;
    while(~scanf("%d",&m))
    {
        int n=(int)sqrt(2.0*m);
        for(int i=1; i<=m; i++)
            scanf("%d",&a[i]);
        sort(a+1,a+m+1);
        f[1]=a[1];
        f[2]=a[2];
        int cnt=3;
        priority_queue<int,vector<int>,greater<int> >q;
        q.push(f[1]+f[2]);
        for(int i=3; i<=m; i++)
        {
            if(!q.empty()&&a[i]==q.top())
                q.pop();
            else
            {
                f[cnt++]=a[i];
                for(int j=1;j<cnt-1;j++)
                    q.push(f[j]+a[i]);
            }
        }
        printf("%d\n",n);
        if(n)
        {
            for(int i=1;i<=n;i++)
            {
                if(i>1)printf(" ");
                printf("%d",f[i]);
            }
            puts("");
        }
    }
    return 0;
}
