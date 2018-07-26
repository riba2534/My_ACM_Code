 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,i,m,j,k;
int a[50];
bool dfs(int i,int sum)
{
    if(i==n)return sum==k;
    if(dfs(i+1,sum))return true;
    if(dfs(i+1,sum+a[i]))return true;
  return false;
}
int main()
{
    while(~scanf("%d %d",&n,&k))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
            printf("%s\n",dfs(0,0)?"YES":"NO");
    }
    return 0;
}
        