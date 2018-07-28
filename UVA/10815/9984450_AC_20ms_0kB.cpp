#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <stack>
#include <set>
#include <queue>
#include <sstream>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 330
#define M 10000+20
#define MOD 1000000000+7
#define inf 0x3f3f3f3f
using namespace std;
set<string>dict;
int main()
{
	string str,s;
	while(cin>>str)
	{
		for(int i=0; i<str.length(); i++)
			if(isalpha(str[i]))
				str[i] = tolower(str[i]);
			else
				str[i]=' ';
		stringstream ss(str);
		while(ss>>s)
			dict.insert(s);
	}
	for(set<string>::iterator it=dict.begin(); it!=dict.end(); it++)
		cout<<*it<<endl;
	return 0;
}
