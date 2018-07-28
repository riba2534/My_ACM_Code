#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <cstring>
#include <string>
#define N 500
#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,m;
int map[N][N];
int cnt;
int go[4][2]= {1,0,-1,0,0,1,0,-1};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mem(map,0);
        cnt=0;
        scanf("%d%d",&m,&n);
        for(int i=0; i<=m+1; i++)
        {
            map[i][0]=0;
            map[i][n+1]=0;
        }
        for(int i=0; i<=n+1; i++)
        {
            map[0][i]=0;
            map[m+1][i]=0;
        }
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
                scanf("%d",&map[i][j]);



//        for(int i=0; i<=m+1; i++)
//        {
//            printf("\n");
//            for(int j=0; j<=n+1; j++)
//                printf("%d ",map[i][j]);
//        }



//----------------------------------------
        for(int i=0; i<=m+1; i++)
        {
            for(int j=0; j<=n+1; j++)
            {
                if(map[i][j]==0)
                {
                    for(int k=0; k<4; k++)
                    {
                        int x=i+go[k][0];
                        int y=j+go[k][1];
                        if(x>=0&&x<=m+1&&y>=0&&y<=n+1&&map[x][y]==1)
                        {
                            cnt++;

                        }
                    }
                }

            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
