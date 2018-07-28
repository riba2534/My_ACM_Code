#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const int N=100+20;
int n;
char mp1[N][N];
int mp2[N][N];
string init()
{
    string s="";
    s+=mp1[1][1];
    int x=1,y=1,op=0;
    while(!(x==n&&y==n))
    {
        if(x==1&&op==0)
        {
            if(y+1<=n) y++;
            else x++;
            op=1;
        }
        else if(y==1&&op==1)
        {
            if(x+1<=n) x++;
            else y++;
            op=0;
        }
        else
        {
            if(op==1)
            {
                if(x+1<=n&&y-1>=1)
                {
                    x++;
                    y--;
                    op=1;
                }
                else
                {
                    y++;
                    op=0;
                }
            }
            else if(op==0)
            {
                if(x-1>=1&&y+1<=n)
                {
                    x--;
                    y++;
                    op=0;
                }
                else
                {
                    x++;
                    op=1;
                }
            }
        }
        s+=mp1[x][y];
    }
    return s;
}
void solve()
{
    mem(mp2,0);
    int x=0,y=0,cnt;
    cnt=mp2[x][y]=1;
    while(cnt<n*n)
    {
        while(y+1<n&&!mp2[x][y+1])  mp2[x][++y]=++cnt;
        while(x+1<n&&!mp2[x+1][y])  mp2[++x][y]=++cnt;
        while(x-1>=0&&!mp2[x-1][y]) mp2[--x][y]=++cnt;
        while(y-1>=0&&!mp2[x][y-1]) mp2[x][--y]=++cnt;
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
            scanf("%s",mp1[i]+1);
        string s=init();
        solve();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                printf("%c",s[mp2[i][j]-1]);
            }
            puts("");
        }
    }
    return 0;;
}
