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
int main()
{
    int t,a,b,c,maxx,minn,i,j;
    scanf("%d",&t);
    while(t--)
    {
        maxx=0,minn=0;
        i=0,j=1;
        scanf("%d%d%d",&a,&b,&c);
        int n=a+b+c;
        for(i=1,j=1; j<=n; i+=2,j++)
        {
            if(j<=a)
                minn+=300*i;
            else if(j>a&&j<=a+b)
                minn+=100*i;
            else if(j>a+b&&j<=a+b+c)
                minn+=50*i;
        }
        for(i=1,j=1; j<=n; i+=2,j++)
        {
            if(j<=c)
                maxx+=50*i;
            else if(j>c&&j<=c+b)
                maxx+=100*i;
            else if(j>c+b&&j<=a+b+c)
                maxx+=300*i;
        }
        printf("%d %d\n",minn,maxx);

    }
    return 0;
}
