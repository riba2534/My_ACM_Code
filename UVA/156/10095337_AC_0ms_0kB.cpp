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
#define N 10000+20
#define ll long long
using namespace std;
map<string,int>mp;
vector<string>v;
string str(string s)//把字符串进行标准化，排序
{
	for(int i=0; i<s.length(); i++)
		s[i]=tolower(s[i]);
	sort(s.begin(),s.end());
	return s;
}
int main()
{
	string s;
	while(cin>>s&&s!="#")
	{
		v.push_back(s);
		string r=str(s);
//		if(!mp.count(r))
//			mp[r]=0;
		mp[r]++;
	}
	vector<string>ans;
	for(int i=0; i<v.size(); i++)
		if(mp[str(v[i])]==1)
			ans.push_back(v[i]);
	sort(ans.begin(),ans.end());
	for(int i=0; i<ans.size(); i++)
		cout<<ans[i]<<endl;
	return 0;
}
