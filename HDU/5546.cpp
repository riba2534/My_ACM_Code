
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N 200200
#define M 1000000
#define ll long long
using namespace std;
char map[15][15],mp[15][15];
int go[4][2]= {0,1,1,0,-1,0,0,-1};
int flag;
void dfs(int x,int y)
{
    for(int i=0; i<4; i++)
    {
        int xx=x+go[i][0];
        int yy=y+go[i][1];
        if(xx>=0&&xx<9&&yy>=0&&yy<9&&mp[xx][yy]=='.')
            flag=1;
        if(xx>=0&&xx<9&&yy>=0&&yy<9&&mp[xx][yy]=='o')
        {
            mp[xx][yy]='#';
            dfs(xx,yy);
        }
    }
}
int jc()
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(mp[i][j]=='o')
            {
                mp[i][j]='#';
                flag=0;
                dfs(i,j);
                if(flag==0)return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int t,q=1;
    scanf("%d",&t);
    while(t--)
    {
        int folg=0;
        for(int i=0; i<9; i++)
            scanf("%s",map[i]);
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(map[i][j]=='.')
                {
                    map[i][j]='x';
                    memcpy(mp,map,sizeof(map));
                    if(jc())folg=1;
                    map[i][j]='.';
                }
            }
        }
        if(folg)
            printf("Case #%d: Can kill in one move!!!\n",q++);
        else
            printf("Case #%d: Can not kill in one move!!!\n",q++);
    }
    return 0;
}