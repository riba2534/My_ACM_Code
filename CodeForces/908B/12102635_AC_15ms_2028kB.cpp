#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
const int N=50+5;
int n,m;
char mp[N][N];
int vis[N][N];
struct node
{
    int x,y;
} st;
int judge(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m&&mp[x][y]!='#')
    {
        if(mp[x][y]=='E')
            return 1;
        else
            return 2;
    }
    else
        return 0;
}
int main()
{
    string s;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>mp[i];
        for(int j=0; j<m; j++)
            if(mp[i][j]=='S')
                st.x=i,st.y=j;
    }
    cin>>s;
    int len=s.length();
    int sum=0;
    int c[4]= {0,1,2,3};//上下左右
    do
    {
        mem(vis,0);
        node sst=st;
        node now[4];
        now[c[0]].x=1,now[c[0]].y=0;
        now[c[1]].x=-1,now[c[1]].y=0;
        now[c[2]].x=0,now[c[2]].y=1;
        now[c[3]].x=0,now[c[3]].y=-1;
        for(int i=0; i<len; i++)
        {
            node to=now[s[i]-'0'];
            int temp=judge(sst.x+to.x,sst.y+to.y);
            if(temp==1)
            {
                sum++;
                break;
            }
            else if(temp==2)
            {
                sst.x+=to.x;
                sst.y+=to.y;
            }
            else if(temp==0)
                break;
        }
    }
    while(next_permutation(c,c+4));
    cout<<sum<<endl;
    return 0;
}

/*
5 6
.....#
S....#
.#....
.#....
...E..
333300012
*/

