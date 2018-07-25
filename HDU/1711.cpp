#include<cstdio>
#include<cstring>
#include<cctype>
#include<string>
#include<set>
#include<iostream>
#include<stack>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N 1000020
#define ll longlong
using namespace std;
int a[N],b[10020],nex_t[10020];
int n,m;
void get_next()//构建next数组
{
    int j=0,k=-1;
    nex_t[0]=-1;
    while(j<m)
    {
        if(k==-1||b[j]==b[k])
            nex_t[++j]=++k;
        else
            k=nex_t[k];
    }
}
int kmp()//返回首次出现位置
{
    int i=0,j=0;
    get_next();
    while(i<n&&j<m)
    {
        if(j==-1||a[i]==b[j])
        {
            i++,j++;
        }
        else
            j=nex_t[j];
    }
    if(j==m)
        return i-m+1;
    return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
            scanf("%d",&b[i]);
        printf("%d\n",kmp());
    }
    return 0;
}
