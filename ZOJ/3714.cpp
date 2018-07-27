#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 100000+20
#define mod 10007
#define M 1000000+10
#define LL long long
using namespace std;
int a[1500];
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        int sum=0,num=0;
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        int len=200-n;
        for(int i=n;i<=300;i++)
        {
            a[i]=a[i%n];
        }
        for(int i=0;i<n;i++)
        {
            sum=0;
            for(int j=i;j<i+m;j++)
            {

                sum+=a[j];
            }
            num=max(sum,num);
        }
        printf("%d\n",num);
    }
    return 0;
}

