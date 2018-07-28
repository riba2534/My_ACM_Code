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
#define N 10000+20
#define ll long long
using namespace std;
vector<int>v[30];
int vis[30];//第几个木块在第几个位置
string s1,s2;
int a,b,n;
void guiwei(int x)//把x上方的木块归位
{
	int w=vis[x];//w代表x在哪一堆
	int j;
	for(int i=0; i<v[w].size(); i++)
		if(v[w][i]==x)
		{
			j=i;
			break;
		}
	for(int i=j+1; i<v[w].size();)
	{
		vis[v[w][j+1]]=v[w][j+1];
		v[v[w][j+1]].push_back(v[w][j+1]);
		v[w].erase(v[w].begin()+j+1);
	}
}
int main()
{
	cin>>n;
	mem(vis,0);
	for(int i=0; i<n; i++)
	{
		v[i].push_back(i);
		vis[i]=i;
	}
	while(cin>>s1&&s1!="quit")
	{
		cin>>a>>s2>>b;
		int wa=vis[a],wb=vis[b];
		if(wa==wb) continue;
		if(s1=="move"&&s2=="onto")
		{
			guiwei(a);
			guiwei(b);
			v[wb].push_back(a);
			v[wa].erase(v[wa].begin()+v[wa].size()-1);
			vis[a]=wb;
		}
		else if(s1=="move"&&s2=="over")
		{
			guiwei(a);
			v[wb].push_back(a);
			v[wa].erase(v[wa].begin()+v[wa].size()-1);
			vis[a]=wb;
		}
		else if(s1=="pile"&&s2=="onto")
		{
			guiwei(b);
			int j;
			for(int i=0; i<v[wa].size(); i++)
				if(v[wa][i]==a)
				{
					j=i;
					break;
				}
			for(int i=j; i<v[wa].size(); )
			{
				vis[v[wa][j]]=wb;
				v[wb].push_back(v[wa][j]);
				v[wa].erase(v[wa].begin()+j);
			}
		}
		else if(s1=="pile"&&s2=="over")
		{
			int j;
			for(int i=0; i<v[wa].size(); i++)
				if(v[wa][i]==a)
				{
					j=i;
					break;
				}

			for(int i=j; i<v[wa].size();)
			{
				vis[v[wa][j]]=wb;
				v[wb].push_back(v[wa][j]);
				v[wa].erase(v[wa].begin()+j);
			}
		}
	}
	for(int i=0; i<n; i++)
	{
		printf("%d:",i);
		for(int j=0; j<v[i].size(); j++)
			printf(" %d",v[i][j]);
		puts("");
	}
	return 0;
}
