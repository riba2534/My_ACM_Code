#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <stack>
#include <iostream>
#include <cstring>
#include <string>
#define N 1000+20
#define inf 0x3f3f3f3f
#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
char map[1000][10];
int vis[1000][10];
int flag=0;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
         scanf("%s",map[i]);
         if(map[i][0]=='O'&&map[i][1]=='O'&&flag==0)
         {
             map[i][0]='+';
             map[i][1]='+';
             flag=1;
         }
         if(map[i][3]=='O'&&map[i][4]=='O'&&flag==0)
         {
             map[i][3]='+';
             map[i][4]='+';
             flag=1;
         }

    }
    if(flag)
    {
        printf("YES\n");
        for(int i=0;i<n;i++)
            printf("%s\n",map[i]);

    }
    else
    {
        printf("NO\n");
    }




    return 0;
}
