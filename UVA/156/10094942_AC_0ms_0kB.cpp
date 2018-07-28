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
//map<string,int>mp;
//vector<string>v;
//string str(string s)
//{
//	for(int i=0;i<s.length();i++)
//		s[i]=tolower(s[i]);
//	sort(s.beg)
//
//}
//int main()
//{
//	string s;
//	while(cin>>s&&s!="#")
//	{
//
//	}
//}
map<string,int>cnt;
vector<string>words;
string repr(string s)
{
	string ans=s;
	for(int i=0; i<ans.length(); i++)
		ans[i]=tolower(ans[i]);
	sort(ans.begin(),ans.end());
	return ans;
}
int main()
{
	int n=0;
	string s;
	while(cin>>s&&s!="#")
	{
		words.push_back(s);
		string  r=repr(s);
		if(!cnt.count(r))
			cnt[r]=0;
		cnt[r]++;
	}
	vector<string>ans;
	for(int i=0; i<words.size(); i++)
		if(cnt[repr(words[i])]==1)
			ans.push_back(words[i]);
	sort(ans.begin(),ans.end());
	for(int i=0; i<ans.size(); i++)
		cout<<ans[i]<<endl;
	return 0;
}
