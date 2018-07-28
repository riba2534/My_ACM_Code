#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define inf 1000000
#define mem(a,b) memset(a,b,sizeof(a))
const int N=20+7;
vector<string>v;
map<char,char>mp;
map<string,string>ans;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    for(int i=0; i<26; i++)
    {
        mp[s[i]]=char(i+'a');
    }
    for(int i=0; i<n; i++)
    {
        cin>>s;
        string str="";
        for(int j=0; j<s.length(); j++)
        {

            str+=mp[s[j]];
        }
        v.push_back(str);
       // cout<<s<<"   "<<str<<endl;
        ans[str]=s;

    }
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++)
        cout<<ans[v[i]]<<endl;




    return 0;
}
