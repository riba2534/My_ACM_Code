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
#define N 100200
#define ll long long
using namespace std;
int main()
{
    int t,n,a,b,c,ab,bc,ac,abc;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans=0;
        while(n--)
        {
            int num=0;
            scanf("%d%d%d%d%d%d%d",&a,&b,&c,&ab,&bc,&ac,&abc);
            int ac0=ac-abc;
            num+=ac0;
            if(ac0<0)continue;
            int bc0=bc-abc;
            num+=bc0;
            if(bc0<0)continue;
            int ab0=ab-abc;
            num+=ab0;
            if(ab0<0)continue;
            int a0=a-(ab0+ac0+abc);
            num+=a0;
            if(a0<0)continue;
            int b0=b-(ab0+bc0+abc);
            num+=b0;
            if(b0<0)continue;
            int c0=c-(ac0+bc0+abc);
            num+=c0;
            if(c0<0)continue;
            num+=abc;
            ans=max(num,ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
