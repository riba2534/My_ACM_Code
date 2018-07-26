 
#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include<list>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define inf 0x3f3f3f3f
typedef long long ll;
stack<char>op;
map<char,int>mp;
void init()
{
    while(!op.empty())op.pop();
    mp['+']=1;
    mp['-']=1;
    mp['*']=2;
    mp['/']=2;
}
void solve(string s)
{
    int len=s.size();
    for(int i=0; i<len; i++)
    {
        if(isdigit(s[i])) cout<<s[i];
        else
        {
            if(s[i]=='(') op.push(s[i]);
            else if(s[i]==')')
            {
                while(!op.empty())
                {
                    char c=op.top();
                    op.pop();
                    if(c=='(')break;
                    cout<<c;
                }
            }
            else
            {
                while(!op.empty()&&mp[s[i]]<=mp[op.top()])
                {
                    cout<<op.top();
                    op.pop();
                }
                op.push(s[i]);
            }
        }
    }
    while(!op.empty())
    {
        cout<<op.top();
        op.pop();
    }
    cout<<endl;
}
int main()
{
    int t;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        init();
        solve(s);
    }
    return 0;
}
        