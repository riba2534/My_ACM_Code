#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 500+20
#define M 1000000+10
#define LL long long
using namespace std;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i=2,sum=0;
        while(1)
        {
            if(i<=n)
                i*=2;
            else
                i=((i-n)*2)-1;
            sum++;
            if(i==2)
                break;
        }
        printf("%d\n",sum);

    }
    return 0;
}
