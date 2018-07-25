#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 200+20
#define M 100000+20
#define inf 0x3f3f3f3f
using namespace std;
map<string,int>mp;
struct node
{
    char str[15];
    int num;
}G[110];
bool cmp(node a,node b)
{
    return a.num>b.num;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        mp.clear();
        int n,sum=0;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>G[i].str>>G[i].num;
        sort(G,G+n,cmp);
        for(int i=0;i<n;i++)
        {
            if(mp[G[i].str]<2)
            {
                sum+=G[i].num;
                mp[G[i].str]++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
