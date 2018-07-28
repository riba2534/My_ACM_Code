#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
char map[1005][1005];
int vis[1005][1005];//火烧
int vix[1005][1005];//人走
int go[4][2]= {{0,1},{0,-1},{-1,0},{1,0}};
int m,n,num,x1,y1;
struct node
{
    int x,y,s,id;
} a[1000];
int bfs(int num)
{
    node now,to;
    queue<node>q;
    for(int i=0; i<num; i++)
    {
        q.push(a[i]);
        vis[a[i].x][a[i].y]=1;
    }
    q.push(a[num]);
    vix[a[num].x][a[num].y]=1;
    while(!q.empty())
    {
        now=q.front();

        if(now.id==0&&(now.x<1||now.y<1||now.x>n||now.y>m))return now.s;
        for(int i=0; i<4; i++)
        {
            to.x=now.x+go[i][0];
            to.y=now.y+go[i][1];
            to.s=now.s+1;
            to.id=now.id;
            if(to.id==0&&vix[to.x][to.y]==0&&vis[to.x][to.y]==0&&map[to.x][to.y]=='.')
            {
                vix[to.x][to.y]=1;
                q.push(to);
            }
            if(to.id==1&&vis[to.x][to.y]==0&&to.x>0&&to.x<=n&&to.y>0&&to.y<=m&&map[to.x][to.y]=='.')
            {
                vis[to.x][to.y]=1;
                q.push(to);
            }
        }
        q.pop();
    }
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mem(map,0);
        mem(vis,0);
        mem(vix,0);
        num=0;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            scanf("%s",map[i]+1);
            for(int j=1; j<=m; j++)
            {
                if(map[i][j]=='F')
                {
                    a[num].x=i;
                    a[num].y=j;
                    a[num].id=1;
                    a[num].s=0;
                    num++;
                }
                if(map[i][j]=='J')
                {
                    x1=i;
                    y1=j;
                }
            }
        }
        a[num].x=x1;
        a[num].y=y1;
        a[num].s=0;
        a[num].id=0;
        for(int i=0; i<=n+1;i++)
        {
            map[i][0]='.';
            map[i][m+1]='.';
        }
        for(int i=0; i<=m+1; i++)
        {
            map[0][i]='.';
            map[n+1][i]='.';
        }
        int ans=bfs(num);
        if(ans)
            printf("%d\n",ans);
        else
            printf("IMPOSSIBLE\n");
    }
//ddd


    return 0;
}
