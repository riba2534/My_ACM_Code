#include<cstdio>
#include<cstring>
#include<cctype>
#include<string>
#include<set>
#include<iostream>
#include<stack>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("whatthefuck!!!")
#define N 1111111
#define M 1000000
#define ll longlong
using namespace std;
int num[150];
int main()
{
    int t,n,x;
    char s[15];
    scanf("%d",&t);
    while(t--)
    {
        mem(num,0);
        scanf("%d",&n);
        int cnt=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%s",s);
            if(s[0]=='L')
            {
                cnt--;
                num[i]=-1;
            }
            if(s[0]=='R')
            {
                cnt++;
                num[i]=1;
            }
            if(s[0]=='S')
            {
                scanf("%s%d",s,&x);
                cnt+=num[x];
                num[i]=num[x];
            }

        }
        printf("%d\n",cnt);
    }
    return 0;
}
