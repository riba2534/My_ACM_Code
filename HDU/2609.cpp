#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define ll long long
using namespace std;
set<string>st;
int max_min_express(string s,bool flag)
{
    int i=0,j=1,k=0,len=s.length();
    while(i<len&&j<len&&k<len)
    {
        int t=s[(j+k)%len]-s[(i+k)%len];
        if(t==0)k++;
        else
        {
            if(flag)
            {
                if(t>0) j+=k+1;
                else i+=k+1;
            }
            else
            {
                if(t>0) i+=k+1;
                else j+=k+1;
            }
            if(i==j) j++;
            k=0;
        }
    }
    return min(i,j);
}
string change(string s)//×éºÏ×Ö·û´®
{
    int k=max_min_express(s,true);
    int len=s.length();
    string str="";
    for(int i=k+1; i<=k+len; i++)
        str+=s[i%len];
    return str;
}
int main()
{
    int n;
    while(cin>>n)
    {
        string s;
        st.clear();
        while(n--)
        {
            cin>>s;
            string str=change(s);
            st.insert(str);
        }
        cout<<st.size()<<endl;
    }
    return 0;
}
