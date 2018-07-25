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
int map[120][120],num;
struct node
{
    int x,y;
} a[120];
int jc(int k,int step)
{
    int x,y;
    for(int i=0; i<4; i++)
        if(map[a[step].x][i]==k||map[i][a[step].y]==k)
            return 0;
    x=(a[step].x/2)*2;
    y=(a[step].y/2)*2;
    for(int i=x;i<x+2;i++)
        for(int j=y;j<y+2;j++)
            if(map[i][j]==k)
                return 0;
    return 1;

}
void dfs(int step)
{

    if(step==num)
    {
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<3; j++)
                cout<<map[i][j];
            cout<<map[i][3]<<endl;
        }
        return;
    }
    for(int i=1; i<=4; i++)
    {
        if(jc(i,step))
        {
            map[a[step].x][a[step].y]=i;
            dfs(step+1);
            map[a[step].x][a[step].y]=0;
        }
    }
}
int main()
{
    int t,q=1;
    scanf("%d",&t);
    while(t--)
    {
        cout<<"Case #"<<q++<<":"<<endl;
        num=0;
        mem(map,0);
        char s;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                cin>>s;
                if(s=='*')
                {
                    a[num].x=i;
                    a[num++].y=j;
                    map[i][j]=0;
                }
                else
                    map[i][j]=s-'0';
            }
        }
        dfs(0);
    }
    return 0;
}