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
#define mod 1000007
#define N 1000
#define M 100000+50
#define ll long long
using namespace std;
char s[20];
int map[4][4];//屏幕快照最后显示的内容
string cover[4][4];//表示能覆盖（i,j）位置的窗口集合
int vis[10];//某个屏幕是否在窗口上出现
int id[10];//入度
int g[10][10];//邻接表
int t;//记录屏幕上出现过的窗口种类数
void calc()//计算出当前方格可能被几号窗口覆盖的可能性
{
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			cover[i][j].erase();
	for(int k=1; k<=9; k++)
	{
		int i=(k-1)/3;
		int j=(k-1)%3;
		cover[i][j]+=char(k+'0');
		cover[i][j+1]+=char(k+'0');
		cover[i+1][j]+=char(k+'0');
		cover[i+1][j+1]+=char(k+'0');
	}
}
void init()
{
	int k;
	mem(vis,0);
	mem(id,0);
	mem(g,0);
	t=0;
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
		{
			scanf("%d",&k);
			map[i][j]=k;
			if(!vis[k]) t++;//记录出现的屏幕种类数
			vis[k]=1;
		}
}
void build()//建图
{
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			for(int p=0; p<cover[i][j].length(); p++)
			{
				int x=map[i][j];
				int y=cover[i][j][p]-'0';
				if(!g[x][y]&&x!=y)//当前x->y没有边，且x和y不是同一条边
				{
					g[x][y]=1;
					id[y]++;
				}
			}
}
int check()
{
	int i,j,k;
	for(k=0; k<t; k++)
	{
		i=1;
		while(!vis[i]||(i<=9&&id[i]>0)) //排除入度大于0的
			i++;
		if(i>9)//大于数字9证明死机了
			return 0;
		vis[i]=0;
		for(j=1; j<=9; j++)
			if(vis[j]&&g[i][j])
				id[j]--;//对入度减一
	}
	return 1;
}
int main()
{
	calc();
	while(1)
	{
		scanf("%s",s);
		if(strcmp(s,"ENDOFINPUT")==0) return 0;
		init();
		build();
		scanf("%s",s);
		if(check()) puts("THESE WINDOWS ARE CLEAN");
		else  puts("THESE WINDOWS ARE BROKEN");
	}
	return 0;
}
