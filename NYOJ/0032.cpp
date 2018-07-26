 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,m;
int num[100];
void dfs(int nn,int mm)
{
    if(mm==0)
    {
        for(int i=m; i>0; i--)
            printf("%d",num[i]);
        printf("\n");
        return;
    }
    for(int i=nn; i>=mm; i--)
    {
        num[mm]=i;
        dfs(i-1,mm-1);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    dfs(n,m);
    return 0;
}
        