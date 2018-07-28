#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 1000+20
#define mod 10007
#define M 1000000+10
#define LL long long
using namespace std;
string add(string a,string b)
{
    string s;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int i=0;
    int m,k=0;
    while(a[i]&&b[i])
    {
        m=a[i]-'0'+b[i]-'0'+k;
        k=m/10;
        s+=(m%10+'0');
        i++;
    }
    if(i==a.size())
    {
        while(i!=b.size())
        {
            m=k+b[i]-'0';
            k=m/10;
            s+=m%10+'0';
            i++;
        }
        if(k)s+=k+'0';
    }
    else if(i==b.size())
    {
        while(i!=a.size())
        {
            m=k+a[i]-'0';
            k=m/10;
            s+=m%10+'0';
            i++;
        }
        if(k)s+=k+'0';
    }
    reverse(s.begin(),s.end());
    return s;
}
int main()
{
    string a,b;
    while(cin>>a>>b)
    {
        cout<<add(a,b)<<endl;
    }

    return 0;
}
