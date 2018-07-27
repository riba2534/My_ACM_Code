#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N 100+20
#define M 1000000+10
#define ll long long
using namespace std;
string division(string str,int x)
{
    string ans="";
    int len=str.length();
    int y=0;
    for(int i=0; i<len; i++)
    {
        ans+=char((y*10+(str[i]-'0'))/x+'0');
        y=(y*10+(str[i]-'0'))%x;
    }
    while(*(ans.begin())=='0'&&ans.size()>1)
        ans.erase(ans.begin());
    return ans;
}
string sub(string a,string b)
{
    int i,j,k,s,flag=1;
    int tmpa[10000],tmpb[10000],c[10000];
    string ans;
    if(a.size()<b.size()||(a.size()==b.size()&&a.compare(b)<0))
    {
        string tmp=a;
        a=b;
        b=tmp;
        flag=0;
    }
    while(a.length()>b.length())b='0'+b;
    int len=a.length();
    for(i=0; i<len; i++)
    {
        tmpa[i]=a[i]-'0';
        tmpb[i]=b[i]-'0';
    }
    for(i=len-1; i>=0; i--)
    {
        if(tmpa[i]>=tmpb[i])
            c[i]=tmpa[i]-tmpb[i];
        else
        {
            c[i]=10+tmpa[i]-tmpb[i];
            tmpa[i-1]--;
        }
    }
    for(i=0; i<len; i++)
        if(c[i]!=0)
            break;
    for(j=i; j<len; j++)
        ans=ans+(char)(c[j]+'0');
    if(!flag)
        ans='-'+ans;
    return ans;

}
int main()
{
    string s;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        int num=(s[s.length()-1]-'0')+(s[s.length()-2]-'0')*10;
        if(s.length()==1)
        {
            if(((s[s.length()-1])-'0')%2)
                cout<<division(s,2)<<endl;
            else
            {
                if(((s[s.length()-1]-'0')/2-1)%2)
                    cout<<sub(division(s,2),"1")<<endl;
                else
                    cout<<sub(division(s,2),"2")<<endl;
            }
        }
        else
        {
            if(num%2)
            {
                cout<<division(s,2)<<endl;
            }
            else
            {
                if((num/2-1)%2)
                    cout<<sub(division(s,2),"1")<<endl;
                else
                    cout<<sub(division(s,2),"2")<<endl;
            }
        }
        if(t)puts("");
    }
    return 0;
}