#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 999999+20
#define M 200010
#define MOD 1000000000+7
#define inf 0x3f3f3f3f
using namespace std;
int main()
{
    int num=0,b=5,c,n;
    scanf("%d",&n);
    while(num<=n)
    {
        c=b;
        while(c%5==0)
        {
            num++;
            c/=5;
        }
        if(num==n)
        {
            printf("5\n");
            for(int i=0; i<5; i++)
                printf("%d ",b+i);
            return 0;
        }
        b+=5;
    }
    printf("0\n");
}
