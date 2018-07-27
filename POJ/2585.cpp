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
int map[4][4];//��Ļ���������ʾ������
string cover[4][4];//��ʾ�ܸ��ǣ�i,j��λ�õĴ��ڼ���
int vis[10];//ĳ����Ļ�Ƿ��ڴ����ϳ���
int id[10];//���
int g[10][10];//�ڽӱ�
int t;//��¼��Ļ�ϳ��ֹ��Ĵ���������
void calc()//�������ǰ������ܱ����Ŵ��ڸ��ǵĿ�����
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
			if(!vis[k]) t++;//��¼���ֵ���Ļ������
			vis[k]=1;
		}
}
void build()//��ͼ
{
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			for(int p=0; p<cover[i][j].length(); p++)
			{
				int x=map[i][j];
				int y=cover[i][j][p]-'0';
				if(!g[x][y]&&x!=y)//��ǰx->yû�бߣ���x��y����ͬһ����
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
		while(!vis[i]||(i<=9&&id[i]>0)) //�ų���ȴ���0��
			i++;
		if(i>9)//��������9֤��������
			return 0;
		vis[i]=0;
		for(j=1; j<=9; j++)
			if(vis[j]&&g[i][j])
				id[j]--;//����ȼ�һ
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
