#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#define N 500
#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
string s;
map<string,int>mp;
vector<string>a;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        s.clear();
        a.clear();
        mp.clear();
        while(cin>>s&&s!="nil")mp[s]=1;
        while(cin>>s&&s!="nil")
            if(mp[s]==1)
                a.push_back(s);
        if(a.size()==0)
            printf("No\n");
        else
            cout<<"Yes"<<" "<<a[0]<<endl;
    }
    return 0;
}