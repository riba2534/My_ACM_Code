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
#define N 10000+20
#define mod 10007
#define M 1000000+10
#define LL long long
using namespace std;
int main()
{
    string s;
    string name[10000];
    map<string,int>mp;
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        mp.clear();
        int flag=1,folg=0;
        for(int i=1;i<=a;i++)
        {
            cin>>s;
            mp[s]=1;
        }
        for(int i=1;i<=b;i++)
            cin>>name[i];
        for(int i=1;i<=c;i++)
        {
            cin>>s;
            mp[s]=0;
        }
        for(int i=1;i<=b;i++)
        {
            if(mp[name[i]]==1)
            {
                if(folg)cout<<" ";
                flag=0;
                cout<<name[i];
                folg++;
            }
        }
        if(flag)
            cout<<"No enemy spy";
        cout<<endl;
    }
    return 0;
}
