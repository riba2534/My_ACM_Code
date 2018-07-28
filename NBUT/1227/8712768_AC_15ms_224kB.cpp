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
string s;
int main()
{
    while(cin>>s)
    {
        LL sum=0;
        int l=s.size();
        for(int i=0; i<l; i++)
            sum=(sum*2)+s[i]-'0';
        cout<<sum<<endl;
    }
    return 0;
}
