#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
typedef long long ll;
const ll N=1e5+20;
string s;
int num[30];
int main()
{
    int n;
    cin>>n>>s;
    if(n>26)
    {
        puts("-1");
        return 0;
    }
    for(int i=0; i<s.length(); i++)
    {
        num[s[i]-'a']++;
    }
    int sum=0;
    for(int i=0; i<26; i++)
    {
        if(num[i]>1)
            sum+=num[i]-1;
    }
    cout<<sum<<endl;
    return 0;
}
