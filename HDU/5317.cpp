#include <cstdio>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
using namespace std;
const int N =1e6+1000;
int isprime[N],prime[N];
int a2[N],a3[N],a4[N],a5[N],a6[N],a7[N];
void init()
{
    mem(isprime,0);//10代表是素数，1代表不是
    int cnt=0;
    isprime[0]=isprime[1]=1;
    for(int i=2; i<N; i++)
    {
        if(isprime[i]==0)
        {
            prime[cnt++]=i;
            for(int j=2*i; j<N; j+=i)
                isprime[j]=1;
        }
    }
}
void biao()
{
    init();
    int numm[10];
    for(int i=0; i<10; i++)
        numm[i]=0;
    for(int i=2; i<N; i++)
    {
        int x=i,j=0,fx=0;
        while(x!=1)
        {
            int flag=0;
            while(x%prime[j]==0)
            {
                flag=1;
                x/=prime[j];
            }
            fx+=flag;
            if(isprime[x]==0)
            {
                fx++;
                break;
            }
            j++;
        }
        numm[fx]++;
        a2[i]=numm[2];
        a3[i]=numm[3];
        a4[i]=numm[4];
        a5[i]=numm[5];
        a6[i]=numm[6];
        a7[i]=numm[7];
    }
}
int main()
{
    biao();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a7[b] - a7[a - 1] >= 2)
            printf("7\n");
        else if (a6[b] - a6[a - 1] >= 2)
            printf("6\n");
        else if (a5[b] - a5[a - 1] >= 2)
            printf("5\n");
        else if (a4[b] - a4[a - 1] >= 2)
            printf("4\n");
        else if (a3[b] - a3[a - 1] >= 2)
            printf("3\n");
        else if (a2[b] - a2[a - 1] >= 2)
            printf("2\n");
        else
            printf("1\n");
    }
    return 0;
}
