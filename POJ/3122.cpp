#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<iostream>
#include <cmath>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N (1010)
#define ll long long
using namespace std;
const double pi=acos(-1.0);
double a[10050];
int main()
{
    int t,n,f,x;
    scanf("%d",&t);
    while(t--)
    {
        double sum=0;
        scanf("%d%d",&n,&f);
        f++;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&x);
            a[i]=x*x;
            sum+=a[i];
        }
        double mid,st=0,ed=sum/f;
        while(ed-st>1e-6)
        {
            mid=(st+ed)/2;
            int cnt=0;
            for(int i=1; i<=n; i++)
                cnt+=(int)(a[i]/mid);
            if(cnt>=f)
                st=mid;
            else
                ed=mid;
        }
        printf("%.4lf\n",mid*pi);
    }
    return 0;
}
