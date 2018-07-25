#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define debug() puts("what the fuck!!!")
#define ll long long
using namespace std;
const ll N=3;
const ll mod=1e9+7;
struct Matrix
{
    ll a[N][N];
    Matrix()
    {
        mem(a,0);
    }
    void init()
    {
        mem(a,0);
        for(ll i=0; i<N; i++)
            a[i][i]=1;
    }
};
Matrix mul(Matrix a,Matrix b)
{
    Matrix ans;
    for(ll i=0; i<N; i++)
        for(ll j=0; j<N; j++)
            for(ll k=0; k<N; k++)
            {
                ans.a[i][j]+=a.a[i][k]*b.a[k][j];
                ans.a[i][j]%=mod;
            }
    return ans;
}
Matrix mat_pow(Matrix a,ll n)
{
    Matrix ans;
    ans.init();
    while(n)
    {
        if(n&1)
            ans=mul(ans,a);
        a=mul(a,a);
        n>>=1;
    }
    return ans;
}
int main()
{
    ll t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n==2)
            puts("3");
        else if(n==3)
            puts("4");
        else if(n==4)
            puts("6");
        else
        {
            Matrix A,B;
            A.a[0][0]=A.a[0][1]=A.a[1][2]=A.a[2][0]=1;
            Matrix p=mat_pow(A,n-4);
            B.a[0][0]=6,B.a[0][1]=4,B.a[0][2]=3;
            Matrix ans=mul(B,p);
            printf("%lld\n",ans.a[0][0]);
        }
    }
    return 0;
}