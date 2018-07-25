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
#define mod 2147493647
#define debug() puts("what the fuck!!!")
#define ll long long
using namespace std;
const ll N=7;
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
                ans.a[i][j]=(ans.a[i][j]%mod+a.a[i][k]*b.a[k][j]%mod)%mod;
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
    ll f1,f2,t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&f1,&f2);
        if(n==1)
            printf("%lld\n",f1);
        if(n==2)
            printf("%lld\n",f2);
        else
        {
            ll zhuanzhi[N][N]=
            {
                1,1,0,0,0,0,0,
                2,0,0,0,0,0,0,
                1,0,1,0,0,0,0,
                4,0,4,1,0,0,0,
                6,0,6,3,1,0,0,
                4,0,4,3,2,1,0,
                1,0,1,1,1,1,1
            };
            Matrix A,B;
            for(ll i=0; i<N; i++)
                for(ll j=0; j<N; j++)
                    B.a[i][j]=zhuanzhi[i][j];
            A.a[0][0]=f2,A.a[0][1]=f1,A.a[0][2]=16;
            A.a[0][3]=8,A.a[0][4]=4,A.a[0][5]=2,A.a[0][6]=1;
            Matrix p=mat_pow(B,n-2);
            Matrix ans=mul(A,p);
            printf("%lld\n",ans.a[0][0]);
        }
    }
    return 0;
}

