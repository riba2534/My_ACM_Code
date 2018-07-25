//#include <stdio.h>
//#include <string.h>
//#include <iostream>
//#include <stack>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#define mem(a,b) memset(a,b,sizeof(a))
//using namespace std;
//int n,m;
//char map[250][250];
//int vis[250][250];
//int x1,x2,y1,y2,amin,bmin,num;
//struct zb
//{
//    int x,y;
//}a[250];
//int dfs(int x,int y,int s)
//{
//
//}
//int main()
//{
//    while(~scanf("%d%d",&n,&m))
//    {
//        num=0;
//        for(int i=0; i<n; i++)
//        {
//            scanf("%s",map[i]);
//            for(int j=0; j<m; j++)
//            {
//                if(map[i][j]=='Y')
//                {
//                    x1=i;
//                    y1=j;
//                }
//                if(map[i][j]=='M')
//                {
//                    x2=i;
//                    y2=j;
//                }
//                if(map[i][j]=='.')
//                {
//                    a[num].x=i;
//                    a[num].y=j;
//                    num++;
//                }
//            }
//            amin=9999;
//            bmin=9999;
//            minn=9999;
//            int amin=dfs(x1,y1,0);
//            int bmin=dfs(x2,y2,0);
//        }
//
//    }
//
//    return 0;
//}
//
#include <stdio.h>
//#include <string.h>
int h,w;
char a[110][110];
void dfs(int x,int y)
{
    if(x>=0&&x<h&&y>=0&&y<w&&a[x][y]=='@')
    {
        a[x][y]='*';
        dfs(x,y+1);
        dfs(x,y-1);
        dfs(x-1,y);
        dfs(x+1,y);
        dfs(x-1,y-1);
        dfs(x+1,y+1);
        dfs(x+1,y-1);
        dfs(x-1,y+1);
    }
    return;
}
int main()
{
    while(scanf("%d%d",&h,&w)!=EOF)
    {

        if(h==0&&w==0)
            break;
        int flag=0;
        for(int i=0; i<h; i++)
            scanf("%s",a[i]);
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                if(a[i][j]=='@')
                {
                    flag++;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",flag);
    }
    return 0;
}
