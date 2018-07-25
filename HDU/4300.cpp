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
#define N 100000+20
#define ll longlong
using namespace std;
int str[60];
int nxt[N],extend[N];
void get_next(string s)
{
    int m=s.length();
    nxt[0]=m;
    int a,p;
    for(int i=1,j=-1; i<m; i++,j--)
    {
        if(j==-1||i+nxt[i-a]>=p)
        {
            if(j==-1)
            {
                p=i;
                j=0;
            }
            while(p<m&&s[p]==s[j])
                p++,j++;
            nxt[i]=j;
            a=i;
        }
        else
            nxt[i]=nxt[i-a];
    }
}
void get_extend(string s,string t)//用s的后缀匹配t的前缀
{
    int n=s.length();
    int m=t.length();
    get_next(t);
    int a,p;
    for(int i=0,j=-1; i<n; i++,j--)
    {
        if(j==-1||i+nxt[i-a]>=p)
        {
            if(j==-1)
            {
                p=i;
                j=0;
            }
            while(p<n&&j<m&&s[p]==t[j])
                p++,j++;
            extend[i]=j;
            a=i;
        }
        else
            extend[i]=nxt[i-a];
    }
}
int main()
{
    int t;
    string s1,s2,s3;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        for(int i=0; i<26; i++)
        {
            char ch=s1[i];
            str[ch]=i;
        }
        s3="";
        for(int i=0; i<s2.length(); i++)
        {
            char ch=str[s2[i]]+'a';
            s3+=ch;
        }
        get_extend(s2,s3);
        int n=s2.length();
        int maxx=s2.length();
        for(int i=0; i<n; i++)
        {
            if(i+extend[i]>=n&&i>=(n+1)/2)
            {
                maxx=i;
                break;
            }
        }
        s3="";
        for(int i=0; i<maxx; i++)
            s3+=s2[i];
        for(int i=0; i<maxx; i++)
        {
            char ch=str[s2[i]]+'a';
            s3+=ch;
        }
        cout<<s3<<endl;
    }
    return 0;
}
