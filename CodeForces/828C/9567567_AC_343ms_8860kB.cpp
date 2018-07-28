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
#define N (3000005)
#define ll long long
using namespace std;
char s[N];
string temp;
int main()
{
	int t,x,n,maxx=0;
	for(int i=0; i<N; i++)s[i]='a';
	scanf("%d",&t);
	while(t--)
	{
		int p=-inf;
		
		cin>>temp; 
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&x);
			if(x-p>=temp.length())
			{
				for(int k=0; k<temp.length(); k++)
					s[x+k]=temp[k];
			}
			else
			{
				int c=0;
				for(int k=x-p; k>0; k--)
				{
					s[p+temp.length()+c]=temp[temp.length()-k];
					c++;
				}
			}
			p=x;
			maxx=max(maxx,x+(int)temp.length());
		}
	}
	s[maxx]='\0';
	printf("%s",s+1);
	return 0;
}
