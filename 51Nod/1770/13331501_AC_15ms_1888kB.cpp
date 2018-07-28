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
#define inf 0x3f3f3f3f
typedef long long ll;
#define mod 10000
const int N=500+20;
int a,b,d,n;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>d>>n;
        int ans=0;
        int l=a*b/10;
        int r=a*b%10;
        if(r==d)
            ans++;
        if(n==1)
        {
            if(l!=0&&l==d)
                ans++;
        }
        else if(n==2)
        {
            if((l+r)%10==d)
                ans++;
            if((l+r)/10+l==d&&d!=0)
                ans++;
        }
        else
        {
            int pos=111*a*b;
            if(pos>=1000&&pos/1000==d)
                ans++;
            pos%=1000;
            if(pos/100==d)
                ans+=n-2;
            pos%=100;
            if(pos/10==d)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
