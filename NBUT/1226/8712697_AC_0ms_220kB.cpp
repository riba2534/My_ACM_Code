#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 1000+20
#define mod 10007
#define M 1000000+10
#define LL long long
using namespace std;
int main()
{
    int t,flag=0;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        if(flag)puts("");;
        if(flag==0) flag=1;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n+1-i; j++)
            {
                if(i*j>9)
                {
                    if(j==n+1-i)
                        printf("%d\n",i*j);
                    else
                        printf("%d ",i*j);
                }
                else
                {
                    if(j==n+1-i)
                    {
                        printf("%d\n",i*j);
                    }
                    else
                    {
                        printf("%d  ",i*j);
                    }
                }


            }
    }
    return 0;
}
