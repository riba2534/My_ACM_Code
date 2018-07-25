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
#define M 12357
#define ll long long
using namespace std;
const int N=105;
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        int ans=0;
        scanf("%d",&n);
        int qqq=sqrt(n-1);
        for(int i=1;i<=qqq;i++)
        {
            if((n-1)%i==0)
                ans+=2;
            if(i*i==n-1)
                ans--;
        }
        printf("%d\n",ans);
    }

    return 0;
}
