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
#define ll longlong
using namespace std;
const int N=1000000+20;
int nxt[N];
string s;
void get_next(string s)
{
    int len=s.length();
    int j=0,k=-1;
    nxt[0]=-1;
    while(j<len)
        if(k==-1||s[j]==s[k])
            nxt[++j]=++k;
        else
            k=nxt[k];
}
int min_max_express(string s,bool flag)//参数为true时求最小表示法，为false为最大表示法
{
    int i=0,j=1,k=0;
    int len=s.length();
    while(i<len&&j<len&&k<len)
    {
        int t=s[(j+k)%len]-s[(i+k)%len];
        //二者相等，后移
        if(t==0) k++;
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
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    while(cin>>s)
    {
        int len=s.length();
        get_next(s);
        int ans=len-nxt[len],cnt=1;
        if(len%ans==0)
            cnt=len/ans;
        cout<<min_max_express(s,true)+1<<" "<<cnt<<" "<<min_max_express(s,false)+1<<" "<<cnt<<endl;
    }
    return 0;
}