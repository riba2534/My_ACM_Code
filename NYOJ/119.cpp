 
#include <cstdio>  
#include <cstring>  
#include <cctype>  
#include <string>  
#include <set>  
#include <iostream>  
#include <stack>  
#include <cmath>  
#include <queue>  
#include <vector>  
#include <algorithm>  
#define mem(a,b) memset(a,b,sizeof(a))  
#define inf 0x3f3f3f3f  
#define mod 10000007  
#define debug() puts("what the fuck!!!")  
#define N 100010  
#define M 1000000  
#define ll long long  
using namespace std;  
int maxx[N][20];  
int minn[N][20];  
void RMQ(int n)  
{  
    for(int j=1; j<20; j++)  
        for(int i=1; i<=n; i++)  
            if(i+(1<<j)-1<=n)  
            {  
                maxx[i][j]=max(maxx[i][j-1],maxx[i+(1<<(j-1))][j-1]);  
                minn[i][j]=min(minn[i][j-1],minn[i+(1<<(j-1))][j-1]);  
            }  
}  
int main()  
{  
    int n,m,a,b,x;  
    scanf("%d%d",&n,&m);  
    for(int i=1; i<=n; i++)  
    {  
        scanf("%d",&x);  
        minn[i][0]=maxx[i][0]=x;  
    }  
    RMQ(n);  
    while(m--)  
    {  
        scanf("%d%d",&a,&b);  
        int k=(int)(log(b-a+1.0)/log(2.0));  
        int maxnum=max(maxx[a][k],maxx[b-(1<<k)+1][k]);  
        int minnum=min(minn[a][k],minn[b-(1<<k)+1][k]);  
        printf("%d\n",maxnum-minnum);  
  
    }  
    return 0;  
}          