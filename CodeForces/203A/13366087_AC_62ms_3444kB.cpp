#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
typedef long long ll;
const int N=1000+20;
int main()
{
    int x,t,a,b,da,db;
    cin>>x>>t>>a>>b>>da>>db;
    int flag=0;
    for(int i=0; i<t; i++)
        for(int j=0; j<t; j++)
            if(a-da*i==x||b-db*j==x||(a-da*i)+(b-db*j)==x||x==0)
                flag=1;
    if(flag)puts("YES");
    else puts("NO");
    return 0;
}
