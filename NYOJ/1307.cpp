 
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
typedef  long long ll;
const int N=20+10;
map<int,string>mp;
void init()
{
    mp[1]="--x";
    mp[2]="-w-";
    mp[3]="-wx";
    mp[4]="r--";
    mp[5]="r-x";
    mp[6]="rw-";
    mp[7]="rwx";
}
int main()
{
    init();
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2,s3="-";
        cin>>s1>>s2;
        for(int i=0 ; i<s1.size(); i++)
            s3+=mp[s1[i]-'0'];
        if(s2==s3)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
        