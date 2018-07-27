#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N (1010000)
#define ll long long
using namespace std;
struct node
{
	int degree,id;//顶点的度数和标号
} v[20];
int map[20][20];
bool cmp(node a,node b)
{
	return a.degree>b.degree;
}
int main()
{
	int t,n,flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&v[i].degree);
			v[i].id=i;//记录顶点的编号
		}
		mem(map,0);
		flag=1;
		for(int k=0; k<n; k++)
		{
			sort(v+k,v+n,cmp);//从第k位开始，对整个数组排序
			int i=v[k].id;//当前要连的顶点的编号
			int d1=v[k].degree;//记录当前这个节点的度数
			if(d1>n-k-1)//当当前节点的度数比剩余的顶点数要大的时候，则不存在相连的关系
				flag=0;
			for(int r=1; r<=d1&&flag; r++)//从当前点开始给后面的度数减一
			{
				int j=v[k+r].id;//当前要连的顶点的编号
				if(v[k+r].degree<=0)//出现负值代表不存在相连的关系
					flag=0;
				v[k+r].degree--;
				map[i][j]=map[j][i]=1;
			}
		}
		if(flag)
		{
			puts("YES");
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					if(j)printf(" ");
					printf("%d",map[i][j]);
				}
				puts("");
			}
		}
		else
			puts("NO");
		if(t)
			puts("");
	}
	return 0;
}
