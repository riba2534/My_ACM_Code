#include <cstdio>  
#include <cstring>  
#include <string>  
#include <set>  
#include <iostream>  
#include <cmath>  
#include <stack>  
#include <queue>  
#include <vector>  
#include <algorithm>  
#define mem(a,b) memset(a,b,sizeof(a))  
#define inf 0x3f3f3f3f  
#define mod 10000007  
#define debug() puts("what the fuck!!!")  
#define N (1010000)  
#define ll long long  
using namespace std;  
int n,m,t,sx,sy,ex,ey,flag;  
char map[60][60];  
int vis[60][60];  
int go[4][2]= {0,1,0,-1,1,0,-1,0};  
void dfs(int x,int y,int step)  
{  
    if(flag)return;  
    if(x==ex&&y==ey&&step==t)  
    {  
        flag=1;  
        return;  
    }  
    int s1=x-ex;  
    int s2=y-ey;  
    if(s1<0)s1=-s1;  
    if(s2<0)s2=-s2;  
    int temp=(t-step)-(s1+s2);  
    if(temp<0||temp&1)return;  
    for(int i=0; i<4; i++)  
    {  
        int xx=x+go[i][0];  
        int yy=y+go[i][1];  
        if(!vis[xx][yy]&&map[xx][yy]!='X'&&xx>=0&&xx<n&&yy>=0&&yy<m)  
        {  
            vis[xx][yy]=1;  
            dfs(xx,yy,step+1);  
            vis[xx][yy]=0;  
        }  
    }  
}  
int main()  
{  
    while(~scanf("%d%d%d",&n,&m,&t)&&(n||m||t))  
    {  
        int wall=0;  
        mem(map,'\0');  
        mem(vis,0);  
        for(int i=0; i<n; i++)  
        {  
            scanf("%s",map[i]);  
            for(int j=0; j<m; j++)  
            {  
                if(map[i][j]=='S')  
                {  
                    sx=i;  
                    sy=j;  
                }  
                if(map[i][j]=='D')  
                {  
                    ex=i;  
                    ey=j;  
                }  
                if(map[i][j]=='X')  
                    wall++;  
            }  
        }  
        if(n*m-wall<=t)  
        {  
            puts("NO");  
            continue;  
        }  
        flag=0;  
        vis[sx][sy]=1;  
        dfs(sx,sy,0);  
        if(flag)  
            puts("YES");  
        else  
            puts("NO");  
    }  
    return 0;  
}  