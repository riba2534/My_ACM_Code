//#include <stdio.h>
//#include <string.h>
//#include <string>
//#include <iostream>
//#include <stack>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#define mem(a,b) memset(a,b,sizeof(a))
//#define inf 0x3f3f3f3f
//#define N 10000+20
//#define M 1000000+10
//#define LL long long
//using namespace std;
//int go[4][2]= {0,1,0,-1,1,0,-1,0};
//char map[10][10],s1[10],s2[10];
//int x1,y1,x2,y2,sx,sy;
//int main()
//{
//
//    gets(s1);
//    gets(s2);
//    for(int i=0; i<3; i++)
//    {
//        map[0][i]=s1[i];
//        map[1][i]=s2[i];
//    }
//    for(int i=0; i<2; i++)
//    {
//        for(int j=0; j<3; j++)
//        {
//            if(map[i][j]=='A')
//            {
//                x1=i;
//                y1=j;
//            }
//            if(map[i][j]=='B')
//            {
//                x2=i;
//                y2=j;
//            }
//            if(map[i][j]==' ')
//            {
//                sx=i;
//                sy=j;
//            }
//        }
//    }
//
//    return 0;
//}
//
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 10000+20
#define M 1000000+10
#define LL long long
using namespace std;
int map[150][150];
int n,m;
int go[4][2]= {0,1,0,-1,1,0,-1,0};
int dfs(int x,int y)
{
    if(map[x][y]==0)
        return 0;
    map[x][y]=0;
    int step=1;
    for(int i=0; i<4; i++)
    {
        int xx=x+go[i][0];
        int yy=y+go[i][1];
        if(xx>=0&&xx<n&&yy>=0&&yy<m&&map[xx][yy]==1)
        {
            step+=dfs(xx,yy);
            map[xx][yy]=0;
        }
    }
    return step;
}
int main()
{

    while(scanf("%d%d",&n,&m)&&(n||m))
    {
        int sum=0;
        memset(map,0,sizeof(map));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(map[i][j]==1)
                {
                    int num=dfs(i,j);
                    sum=max(sum,num);
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}










