#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N 500010
#define M 1000000
#define ll long long
using namespace std;
struct node
{
    string name;
    int kill_num;
    int num;
} a[300];
bool cmp(node a,node b)
{
    if(a.kill_num==b.kill_num)
        return a.name<b.name;
    else
        return a.kill_num>b.kill_num;
}
int main()
{
    int n,q;
    while(cin>>n)
    {
        int len=1;
        map<string,int>mp;
        if(n==0)return 0;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i].name>>a[i].kill_num;
            mp[a[i].name]=a[i].kill_num;
        }

        sort(a+1,a+n+1,cmp);
        a[1].num=1;
        int flag=0;
        for(int i=1; i<=n; i++)
        {
            cout<<a[i].name<<" "<<a[i].kill_num<<endl;
            if(i>1)
            {
                if(a[i].kill_num==a[i-1].kill_num)
                {
                     a[i].num=a[i-1].num;
                     flag++;
                }
                else
                {
                    a[i].num=a[i-1].num+1+flag;
                    flag=0;
                }

            }

        }
        cin>>q;
        string s;
        while(q--)
        {
            cin>>s;
             flag=0;
            for(int i=1;i<=n;i++)
            {
                if(mp[s]==a[i].kill_num)
                    flag++;
                if(a[i].name==s)
                {
                    if(flag>1)
                        printf("%d %d\n",a[i].num,flag);
                    else
                        printf("%d\n",a[i].num);
                    break;
                }
            }
        }
    }
    return 0;
}
