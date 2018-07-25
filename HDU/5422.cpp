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
#define N 100000+20
#define mod 10007
#define M 1000000+10
#define LL long long
using namespace std;
int main()
{
    int n,m,a,b;
    while(~scanf("%d%d",&n,&m))
    {
        int flag=0;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&a,&b);
            if((a==1&&b==n)||(a==n&&b==1))
                flag=1;
        }
        if(flag)
            printf("%d %d\n",1,n*(n-1)/2);
        else
            printf("1 1\n");
    }
    return 0;
}
