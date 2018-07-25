#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;
typedef long long int LL;
const int INF=2e9+1e8;
const int maxn=1e5+5;

const int MOD=10000007;
int n;
struct Mat
{
    LL mat[12][12];
    void init()
    {
        memset(mat,0,sizeof(mat));
    }
    void E()
    {
        init();
        for(int i=0;i<n;i++) mat[i][i]=1;
    }
    void show()
    {
        printf("debug\n");
        for(int i=0;i<=n+1;i++,puts(""))
            for(int j=0;j<=n+1;j++)
                printf("%lld ",mat[i][j]);
        printf("Over\n");
    }
};
Mat operator *(Mat a,Mat b)
{
    Mat res;
    res.init();
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=n+1;j++)
            for(int k=0;k<=n+1;k++)
                res.mat[i][j]+=a.mat[i][k]*b.mat[k][j],res.mat[i][j]%=MOD;
    return res;
}
Mat ksm(Mat a,int b)
{
    Mat res;
    res.E();
    while(b>0)
    {
        if(b&1) res=a*res;
        a=a*a;
        b>>=1;
    }
    return res;
}
Mat getmat()
{
    Mat res;
    res.init();
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++) res.mat[i][j]=1;
    for(int i=0;i<=n;i++) res.mat[n][i]=10;
    for(int i=0;i<=n+1;i++) res.mat[n+1][i]=1;
    return res;
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        Mat ori;
        ori.init();
        ori.mat[0][n]=23;
        ori.mat[0][n+1]=3;
        for(int i=n-1;i>=0;i--) scanf("%lld",&ori.mat[0][i]);
        Mat res=ori*ksm(getmat(),m);
        printf("%lld\n",res.mat[0][0]);
    }
    return 0;
}
