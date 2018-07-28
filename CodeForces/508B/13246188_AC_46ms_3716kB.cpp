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
const int N=100000+7;
int main()
{
    string s;
    cin>>s;
    int ans=-1;
    int len=s.length();
    for(int i=0; i<len; i++)
    {
        if((s[i]-'0')%2==0)
        {
            ans=i;
            if(s[i]<s[len-1])
                break;
        }
    }
    if(ans==-1)
        cout<<-1<<endl;
    else
    {
        swap(s[ans],s[len-1]);
        cout<<s<<endl;
    }
    return 0;
}
