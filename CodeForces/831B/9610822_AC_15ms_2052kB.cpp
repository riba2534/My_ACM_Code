#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 1000007
#define N 8
#define M 12357
#define ll long long
using namespace std;
map<int,int>mp;
int main()
{
	//printf("%d %d\n",'a','A');
	char s1[30],s2[30],s3[1010];
	scanf("%s%s%s",s1,s2,s3);
	for(int i=0;i<strlen(s1);i++)
	{
		//if(s3[i]>='a'&&s3[i]<='z')
		mp[s1[i]]=s2[i];
	}
	for(int i=0;i<strlen(s3);i++)
	{
		if(s3[i]>='a'&&s3[i]<='z')
		{
			printf("%c",tolower(mp[s3[i]]));
		}
		else if(s3[i]>='A'&&s3[i]<='Z')
		{
			printf("%c",toupper(mp[s3[i]+('a'-'A')]));
		}
		else
		{
			printf("%c",s3[i]);
		}

	}
	puts("");
	return 0;
}