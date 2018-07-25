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
const int N=10000+7;
int a[N],c1[N],c2[N];
int main()
{
    int n,sum;
    while(~scanf("%d",&n))
    {
        sum=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        mem(c1,0);
        mem(c2,0);
        for(int i=0; i<=a[0]; i+=a[0]) //第一个表达式，每次只能取0和1
            c1[i]=1;
        for(int i=1; i<n; i++) //第i个表达式
        {
            for(int j=0; j<=sum; j++) //表达式的第j项
            {
                //k表示每个表达式的第j个指数
                for(int k=0; k<=a[i]; k+=a[i])
                {
                    c2[k+j]+=c1[j];
                    c2[abs(j-k)]+=c1[j];
                }
            }
            for(int j=0; j<=sum; j++)
            {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        n=0;
        for(int i=1; i<=sum; i++)
        {
            if(c1[i]==0)
                n++;
        }
        printf("%d\n",n);
        if(n)
        {
            int flag=1;
            for(int i=1; i<=sum; i++)
            {
                if(c1[i]==0)
                {
                    if(!flag)
                        printf(" ");
                    else
                        flag=0;
                    printf("%d",i);
                }
            }
            puts("");
        }
    }
    return 0;
}
