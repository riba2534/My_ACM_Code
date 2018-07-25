#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define inf 1000000
#define mem(a,b) memset(a,b,sizeof(a))
const int N=1000+7;
int a[N],b[N];
int v[N];
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=1; i<=17; i++)
            v[i]=i*i;
        mem(a,0);
        a[0]=1;
        for (int i=1; i<=17; i++)
        {
            mem(b,0);
            for (int j=0; j*v[i]<=n; j++) //循环每个因子的每一项
                for (int k=0; k+j*v[i]<=n; k++) //循环a的每个项
                    b[k+j*v[i]]+=a[k];//把结果加到对应位
            memcpy(a,b,sizeof(b));//b赋值给a
        }
        printf("%d\n",a[n]);
    }
    return 0;
}
