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
#define N 100+20
#define M 1000000+10
#define LL long long
using namespace std;
int a[M];
void biao()
{
    double x=1;
    for(int i=1; i<=M; i++)
    {
        x+=log10(double(i));
        a[i]=floor(x);
    }

}
int main()
{

    int n;
    biao();
    while(~scanf("%d",&n))
        printf("%d\n",a[n]);
    return 0;
}
