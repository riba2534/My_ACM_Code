//#include <cstdio>
//#include <cstring>
//#include <cctype>
//#include <stdlib.h>
//#include <string>
//#include <map>
//#include <iostream>
//#include <stack>
//#include <cmath>
//#include <queue>
//#include <vector>
//#include <algorithm>
//using namespace std;
//typedef long long ll;
//#define inf 0x3f3f3f3f
//#define mem(a,b) memset(a,b,sizeof(a))
//const int N=100000+20;
//int a[N];
//int dp[N];
//int val[N];
//int main()
//{
//    int t,n,x;
//    scanf("%d",&t);
//    while(t--)
//    {
//        mem(a,0);
//        mem(dp,inf);
//        scanf("%d",&n);
//        for(int i=0; i<n; i++)
//            scanf("%d",&a[i]);
//        for(int i=0; i<n; i++)
//            scanf("%d",&val[i]);
//        int len=0,sum=0;
//        for(int i=0; i<n; i++)
//        {
//            int p=lower_bound(dp,dp+len,a[i])-dp;
//            for(int j=p; j<p+val[i]; j++)
//            {
//                dp[j]=a[i];
//                if(j==len)len++;
//            }
//        }
//        printf("%d\n",len);
//    }
//    return 0;
//}
#include<bits/stdc++.h>
using namespace std;
map<string,set<string> >mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,t;
    cin>>n;
    string s,x;
    for(int i=1; i<=n; i++)
    {
        cin>>s>>t;
        for(int j=0; j<t; j++)
        {
            cin>>x;
            mp[s].insert(x);
        }
    }
    cout<<mp.size()<<"\n";
    for(auto &i:mp)
    {
        set<string> &tmp=i.second;
        for(auto &x:tmp)
            for(int y=1; y<x.size(); y++)
                if(tmp.count(string(x.begin()+y,x.end())))
                    tmp.erase(string(x.begin()+y,x.end()));
        cout<<i.first<<" "<<tmp.size()<<" ";
        for(auto x:i.second)
            cout<<x<<" ";
        cout<<"\n";
    }
}
