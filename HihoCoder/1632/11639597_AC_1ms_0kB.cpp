//#include <cstdio>
//#include <cstring>
//#include <cctype>
//#include <string>
//#include <set>
//#include <iostream>
//#include <stack>
//#include <cmath>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#define mem(a,b) memset(a,b,sizeof(a))
//#define inf 0x3f3f3f3f
//using namespace std;
//const int N=200+20;
//char mp[N][N];
//int n;
//int go[4][2]= {0,1,1,-1,1,0,-1,1};
//string s;
//void dfs(int x,int y)
//{
//    s+=mp[x][y];
//    while(!(x==n&&y==n))
//    {
//        for(int k=0; k<4; k++)
//        {
//            cout<<"s="<<s<<endl;
//            int xx=x+go[k][0];
//            int yy=y+go[k][1];
//            if()
//            if(xx>=1&&xx<=n&&yy>=1&&yy<=n)
//            {
//                if(k==0)
//                {
//                    x=xx,y=yy;
//                    s+=mp[x][y];
//                    if(x==n&&y==n)break;
//                }
//                else if(k==1)
//                {
//                    x=xx,y=yy;
//                    while(y!=1)
//                    {
//                        s+=mp[x][y];
//                        x+=go[k][0];
//                        y+=go[k][1];
//                    }
//                    s+=mp[x][y];
//                    if(x==n&&y==n)break;
//                }
//                else if(k==2)
//                {
//                    x=xx,y=yy;
//                    s+=mp[x][y];
//                    if(x==n&&y==n)break;
//                }
//                else if(k==3)
//                {
//                    x=xx,y=yy;
//                    while(x!=1)
//                    {
//                        s+=mp[x][y];
//                        x+=go[k][0];
//                        y+=go[k][1];
//                    }
//                    s+=mp[x][y];
//                    if(x==n&&y==n)break;
//                }
//            }
//            else
//                break;
//        }
//    }
//}
//int main()
//{
//    while(~scanf("%d",&n))
//    {
//        for(int i=1; i<=n; i++)
//            scanf("%s",mp[i]+1);
//        s="";
//        dfs(1,1);
//        cout<<s<<endl;
//    }
//    return 0;
//}
//
//


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
        while(y+1<n&&!mp2[x][y+1])  mp2[x][++y] =++cnt;
        while(x+1<n&&!mp2[x+1][y]) mp2[++x][y]=++cnt;
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
