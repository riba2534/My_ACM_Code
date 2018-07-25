#include <stdio.h>
#include <algorithm>
#include <algorithm>
#include <string.h>
#include <string>
#include <iostream>
#include <queue>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const int N=4e5+10;
int fac[10]= {0,1,2,6,24,120,720,5040,40320,362880};
string path[N];
int vis[N];
int go[4][2]= {-1,0,1,0,0,-1,0,1}; //上下左右
char dir[]="durl";//和方向变量相反
struct node
{
    int s[9];//序列
    int zero_pos;//0的位置
    int hash;//哈希值
    string path;//路径
};
int cantor_hash(int s[])//康托展开判重
{
    int res=0;
    for(int i=0; i<9; i++)
    {
        int num=0;
        for(int j=i+1; j<9; j++)
            if(s[i]>s[j])
                num++;
        res+=(num*fac[9-i-1]);
    }
    return res;
}
void init()
{
    node now,to;
    mem(vis,0);
    for(int i=0; i<8; i++)
        now.s[i]=i+1;
    now.s[8]=0;
    now.zero_pos=8;
    now.hash=cantor_hash(now.s);
    path[now.hash]="";
    vis[now.hash]=1;
    queue<node>q;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        int x=now.zero_pos/3;
        int y=now.zero_pos%3;
        for(int i=0; i<4; i++)
        {
            int xx=x+go[i][0];
            int yy=y+go[i][1];
            if(xx>=0&&xx<3&&yy>=0&&yy<3)
            {
                to=now;
                to.zero_pos=xx*3+yy;
                to.s[now.zero_pos]=to.s[to.zero_pos];
                to.s[to.zero_pos]=0;
                to.hash=cantor_hash(to.s);
                if(!vis[to.hash])
                {
                    to.path=dir[i]+now.path;
                    path[to.hash]=to.path;
                    q.push(to);
                    vis[to.hash]=1;
                }
            }
        }
    }
}

int main()
{
    init();
    node ans;
    char s[5];
    while(~scanf("%s",s))
    {
        if(s[0]=='x')
        {
            ans.zero_pos=0;
            ans.s[0]=0;
        }
        else
            ans.s[0]=s[0]-'0';
        for(int i=1; i<9; i++)
        {
            scanf("%s",s);
            if(s[0]=='x')
            {
                ans.zero_pos=i;
                ans.s[i]=0;
            }
            else
                ans.s[i]=s[0]-'0';
        }
        ans.hash=cantor_hash(ans.s);
        if(vis[ans.hash])
            cout<<path[ans.hash]<<endl;
        else
            puts("unsolvable");
    }
    return 0;
}
