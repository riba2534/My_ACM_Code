#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const int N=10000+50;
int main()
{
    string s;
    int n,ans=0;
    cin>>n>>s;
    for(int i=0; i<n; i++)
        if(s[i]=='H')ans^=i+1;
    puts(ans==0?"Bob":"Alice");
    return 0;
}
