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
	int degree,id;//����Ķ����ͱ��
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
			v[i].id=i;//��¼����ı��
		}
		mem(map,0);
		flag=1;
		for(int k=0; k<n; k++)
		{
			sort(v+k,v+n,cmp);//�ӵ�kλ��ʼ����������������
			int i=v[k].id;//��ǰҪ���Ķ���ı��
			int d1=v[k].degree;//��¼��ǰ����ڵ�Ķ���
			if(d1>n-k-1)//����ǰ�ڵ�Ķ�����ʣ��Ķ�����Ҫ���ʱ���򲻴��������Ĺ�ϵ
				flag=0;
			for(int r=1; r<=d1&&flag; r++)//�ӵ�ǰ�㿪ʼ������Ķ�����һ
			{
				int j=v[k+r].id;//��ǰҪ���Ķ���ı��
				if(v[k+r].degree<=0)//���ָ�ֵ�������������Ĺ�ϵ
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
