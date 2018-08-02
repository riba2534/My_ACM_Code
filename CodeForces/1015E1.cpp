#include <bits/stdc++.h>
using namespace std;
const int N=1000+20;
char s[N][N];
int vis[N][N];
int n,m;
struct pos
{
    int x,y,s;
    pos(int _x,int _y,int _s)
    {
        x=_x,y=_y,s=_s;
    }
};
vector<pos>v;
int pd(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m&&s[x][y]=='*')
        return 1;
    return 0;
}
int get_len(int x,int y)
{
    int len=0;
    for(int i=1;; i++)
    {
        if(pd(x-i,y)&&pd(x+i,y)&&pd(x,y-i)&&pd(x,y+i))
        {
            vis[x][y]=1;
            len=i;
            vis[x-i][y]=vis[x+i][y]=vis[x][y-i]=vis[x][y+i]=1;
        }
        else
            break;
    }
    return len;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%s",s[i]);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(s[i][j]=='*')
            {
                int len=get_len(i,j);
                if(len>0)
                    v.push_back(pos(i,j,len));
            }
    int flag=1;
    for(int i=0; i<n&&flag; i++)
        for(int j=0; j<m&&flag; j++)
            if(s[i][j]=='*'&&!vis[i][j])
                flag=0;
    if(flag)
    {
        printf("%d\n",v.size());
        for(pos ans:v)
            printf("%d %d %d\n",ans.x+1,ans.y+1,ans.s);
    }
    else
        puts("-1");
    return 0;
}
/*
5 5
.*...
****.
.****
..**.
.....
*/
