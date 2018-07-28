#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 330
#define M 10000+20
#define MOD 1000000000+7
#define inf 0x3f3f3f3f
using namespace std;
char map[6][6];
int judge(int x,int y)
{
	int cnt=0;
	//上下
	for(int i=x;i<4;i++)
	{
		if(map[i][y]=='x')
			cnt++;
		else
			break;
	}
	for(int i=x-1; i>=0; i--)
	{
		if(map[i][y]=='x')
			cnt++;
		else
			break;
	}
	if(cnt>=3) return 1;
	cnt=0;
	//左右
	for(int i=y; i<4; i++)
	{
		if(map[x][i]=='x')
			cnt++;
		else
			break;
	}
	for(int i=y-1; i>=0; i--)
	{
		if(map[x][i]=='x')
			cnt++;
		else
			break;
	}
	if(cnt>=3) return 1;
	cnt=0;

	for(int i = x, j = y; (i >= 0 && i <4 && j >= 0 && j <4); i--, j--)
	{
		if(map[i][j]=='x')
			cnt++;
		else
			break;
	}
	for(int i = x + 1, j = y + 1; (i >= 0 && i <4 && j >= 0 && j <4); i++, j++)
	{
		if(map[i][j] == 'x')
		{
			cnt++;
		}
		else
			break;
	}
	if(cnt>=3) return 1;
	cnt=0;

	for(int i = x, j = y; (i >= 0 && i <4 && j >= 0 && j <4); i--, j++)
	{
		if(map[i][j] == 'x')
		{
			cnt++;
		}
		else
			break;
	}
	for(int i = x + 1, j = y - 1; (i >= 0 && i <4 && j >= 0 && j <4); i++, j--) //由当前点斜下左下
	{
		if(map[i][j] == 'x')
		{
			cnt++;
		}
		else
			break;
	}
	if(cnt>=3) return 1;
	return 0;
}
int main()
{
	int flag=0;
	for(int i=0; i<4; i++)
		scanf("%s",map[i]);
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			if(map[i][j]=='.')
			{
				map[i][j]='x';
				if(judge(i,j))
				{
					flag=1;
					break;
				}
				map[i][j]='.';
			}
		}
		if(flag)break;
	}

	if(flag)
		puts("YES");
	else
		puts("NO");
	return 0;
}
