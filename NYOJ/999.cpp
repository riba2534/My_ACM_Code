 
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N 1001000
#define M 1000000
#define ll long long
using namespace std;
int n,m,t,ans;
char map[120][120];
int vis[120][120][4];
int go[4][2]= {0,1,0,-1,1,0,-1,0};
struct node
{
    int x,y,step,st;
};
int check(int x,int y)
{
    if(map[x][y]=='X'||map[x][y]=='D'||map[x][y]=='E')
        return 0;
    return 1;
}
char solve(int chr,int op)
{
    if(op==1&&chr=='e'||op==0&&chr=='d')//如果两个有交点，那么返回'y'
        return 'y';
    return op?'d':'e';//判断状态，状态为0时把所在得点变为'e',为1时把状态变成'd'
}
void update(int x,int y,int ok)//更新各个点的字符,目的是把D所在的行和列全部更新成d，把E所在的行和列全部更新成e，如果这两个有交叉就用y来表示
{
    for(int i=x+1; i<m&&check(i,y); i++) //向右遍历，且不怕碰到墙或者D和E
        map[i][y]=solve(map[i][y],ok);
    for(int i=x-1; i>=0&&check(i,y); i--) //向左
        map[i][y]=solve(map[i][y],ok);
    for(int i=y+1; i<n&&check(x,i); i++) //向下遍历，且不怕碰到墙或者D和E
        map[x][i]=solve(map[x][i],ok);
    for(int i=y-1; i>=0&&check(x,i); i--) //向上
        map[x][i]=solve(map[x][i],ok);
}
int st_solve(char x,int st)//状态压缩
{
    if(x=='d') st|=1;
    if(x=='e') st|=2;
    if(x=='y') st|=3;
    return st;
}
void bfs(node s)
{
    s.step=0;
    s.st=st_solve(map[s.x][s.y],0);
    mem(vis,0);
    queue<node>q;
    q.push(s);
    vis[s.x][s.y][s.st]=1;
    while(!q.empty())
    {
        node now=q.front(),to;
        q.pop();
        if(now.st==3)
        {
            ans=now.step;
            return;
        }
        for(int i=0;i<4;i++)
        {
            to.x=now.x+go[i][0];
            to.y=now.y+go[i][1];
            to.step=now.step+1;
            to.st=now.st;
            if(check(to.x,to.y)&&vis[to.x][to.y][to.st]==0&&to.x>=0&&to.x<n&&to.y>=0&&to.y<=m)//没有标记过，不越界，且不是墙和D,E
            {
                to.st=st_solve(map[to.x][to.y],to.st);
                vis[to.x][to.y][to.st]=1;
                q.push(to);
            }
        }
    }
}
int main()
{
    int q=1;
    while(~scanf("%d%d%d",&n,&m,&t))
    {
        mem(map,0);
        node s;
        for(int i=0; i<n; i++)
        {
            scanf("%s",map[i]);
            for(int j=0; j<m; j++)
            {
                if(map[i][j]=='S')
                {
                    s.x=i;
                    s.y=j;
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(map[i][j]=='D')
                    update(i,j,1);
                if(map[i][j]=='E')
                    update(i,j,0);
            }
        }
//        puts("");
//        for(int i=0; i<n; i++,puts(""))
//            for(int j=0; j<m; j++)
//                printf("%c ",map[i][j]);
        ans=inf;
        bfs(s);
        printf("Case %d:\n",q++);
        if(ans>t)
            puts("-1");
        else
            printf("%d\n",ans);
    }
    return 0;
}
        