#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pir;
const int inf=1e9+7;
const int N=2e5+20;
int main()
{
    string s;
    cin>>s;
    int len=s.size();
    int a=0,b=len-1;
    while(a<b)
    {
        if(s[a]!=s[b]) break;
        a++,b--;
    }
    while(s[a]==s[a-1])
        a--;
    cout<<a+1<<endl;
    return 0;
}


