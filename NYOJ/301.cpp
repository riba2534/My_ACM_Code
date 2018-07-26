 
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
#define N 3
#define M 1000000+10
#define ll long long
using namespace std;
struct matrix
{
    ll map[3][3];
};
matrix unit_matrix=
{
    1,0,0,
    0,1,0,
    0,0,1
};//单位矩阵
matrix mul(matrix a,matrix b)
{
    matrix res;
    for(ll i=0; i<3; i++)
        for(ll j=0; j<3; j++)
        {
            res.map[i][j]=0;
            for(ll k=0; k<3; k++)
                res.map[i][j]=(res.map[i][j]+a.map[i][k]*b.map[k][j])%mod;
        }
    return res;
}
matrix pow_matrix(matrix a,ll n)
{
    matrix res=unit_matrix;
    while(n)
    {
        if(n&1)
            res=mul(res,a);
        a=mul(a,a);
        n>>=1;
    }
    return res;
}
int main()
{
    ll t,f1,f2,a,b,c,n;
    scanf("%lld",&t);
    matrix tmp,arr;
    while(t--)
    {
        scanf("%lld%lld%lld%lld%lld%lld",&f1,&f2,&a,&b,&c,&n);
        if(n==1)
            printf("%lld\n",(f1+mod)%mod);
        else if(n==2)
            printf("%lld\n",(f2+mod)%mod);
        else
        {
            mem(arr.map,0);
            mem(tmp.map,0);
            arr.map[0][0]=f2,arr.map[0][1]=f1,arr.map[0][2]=1;
            tmp.map[0][0]=b,tmp.map[1][0]=a,tmp.map[2][0]=c;
            tmp.map[0][1]=1,tmp.map[2][2]=1;
            matrix p=pow_matrix(tmp,n-2);
            p=mul(arr,p);
            ll ans=(p.map[0][0]+mod)%mod;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
        