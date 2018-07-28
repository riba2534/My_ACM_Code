#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
typedef long long ll;
#define mod 10000
const int N=500+20;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int ans;
        string s;
        cin>>s;
        int len=s.length();
        if(len==5)
            ans=3;
        else
        {
            if((s[0]=='o'&&s[2]=='e')||(s[1]=='n'&&s[2]=='e')||(s[0]=='o'&&s[1]=='n'))
                ans=1;
            else
                ans=2;

        }
        cout<<ans<<endl;
    }

    return 0;
}
