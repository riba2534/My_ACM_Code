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
int w[4]= {0,1,2,5};
int n[4],a[8005],b[8005],ans,lst;
void init()
{
    mem(a,0);
    a[0]=1;
    lst=0;
    for(int k=1; k<=3; k++)
    {
        lst+=w[k-1]*n[k-1];//求出最高次数
        for(int i=0; i<=lst; i++)
            for(int j=0; j<=n[k]; j++)
                b[i+j*w[k]]+=a[i];
        memcpy(a,b,sizeof(a));
        mem(b,0);
    }
}

int main()
{
    while(scanf("%d%d%d",&n[1],&n[2],&n[3])&&n[1]+n[2]+n[3])
    {
        init();
        ans=0;
        while(a[ans])ans++;
        printf("%d\n",ans);
    }
    return 0;
}

