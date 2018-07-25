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
string str[100];
int cnt;
string sub(string a, string b)
{
    int i, j, k, s, flag = 1;
    int tmpa[10000], tmpb[10000], c[10000];
    string ans;
    if(a.size() < b.size() || (a.size() == b.size() && a.compare(b) < 0))
    {
        string tmp = a;
        a = b;
        b = tmp;
        flag = 0;
    }
    while(a.length() > b.length()) b = '0' + b;
    int len = a.length();
    for(i = 0; i < len; i++)
    {
        tmpa[i] = a[i] - '0';
        tmpb[i] = b[i] - '0';
    }
    for(i = len - 1; i >= 0; i--)
    {
        if(tmpa[i] >= tmpb[i])
            c[i] = tmpa[i] - tmpb[i];
        else
        {
            c[i] = 10 + tmpa[i] - tmpb[i];
            tmpa[i-1]--;
        }
    }
    for(i = 0; i < len - 1; i++)
        if(c[i] != 0)
            break;
    for(j = i; j < len; j++)
        ans = ans + (char)(c[j] + '0');
    if(!flag)
        ans = '-' + ans;
    return ans;
}
int change(string s)
{
    int num=(s[0]-'0')*10+(s[1]-'0');
    return num;
}
void jg_19(string s)
{
    int len=s.length();
    if(len==1)
    {
        str[cnt++]=s;
        //cout<<s<<endl;;
    }
    else if(len==2)
    {
        int num=(s[0]-'0')*10+(s[1]-'0');
        if(num<=18)
        {
            string s1=sub(s,"9");
            str[cnt++]="9";
            str[cnt++]=s1;
            //cout<<s1<<endl;
        }
        else if(num==19)
        {
            str[cnt++]="11";
            str[cnt++]="8";
        }
    }
}
void calc(string s)
{
    int len=s.length();
    if(len==1)
    {
        str[cnt++]=s;
        //cout<<s<<endl;;
    }
    else if(len==2)
    {
        int num=(s[0]-'0')*10+(s[1]-'0');
        if(num<=18)
        {
            string s1=sub(s,"9");
            str[cnt++]="9";
            str[cnt++]=s1;
            //cout<<s1<<endl;
        }
        else if(num==19)
        {
            str[cnt++]="11";
            str[cnt++]="8";
        }
        else
        {
            while(1)
            {
                string s1="";
                s1+=s[0]-1;
                s1+=s1;
                str[cnt++]=s1;
                //cout<<s1<<endl;
                s=sub(s,s1);
                if(change(s)<=19)
                {
                    jg_19(s);
                    break;
                }
                if(s.length()<2)
                {
                    str[cnt++]=s;
                    //cout<<s<<endl;
                    break;
                }
            }
        }
    }
}
int main()
{
//      freopen("in.txt","r",stdin);
//      freopen("out2.txt","w",stdout);
    string s;
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t,q=1;
    cin>>t;
    while(t--)
    {
        cnt=0;
        cin>>s;
        cout<<"Case #"<<q++<<":"<<endl;
        int len=s.length();
        if(len==1)
            str[cnt++]=s;
        else if(len==2)
            calc(s);
        else
        {
            while(len>2)
            {
                string s1="";
                if(len<2)
                {
                    if(len&1)
                    {
                        if(s[(len+1)/2-1]=='0')
                        {
                            for(int i=0; i<len-1; i++)
                                s1+="9";
                            str[cnt++]=s1;
                            //cout<<s1<<endl;
                            s=sub(s,s1);
                        }
                        else
                        {
                            for(int i=0; i<len/2; i++)
                                s1+=s[i];
                            string s2=s1;
                            s1+=s[(len+1)/2-1]-1;
                            reverse(s2.begin(),s2.end());
                            s1+=s2;
                            str[cnt++]=s1;
                            //cout<<s1<<endl;
                            s=sub(s,s1);
                        }
                    }
                    else
                    {
                        if(s[len/2-1]=='0')
                        {
                            for(int i=0; i<len-1; i++)
                                s1+="9";
                            str[cnt++]=s1;
                            //cout<<s1<<endl;
                            s=sub(s,s1);
                        }
                        else
                        {
                            for(int i=0; i<len/2; i++)
                                s1+=s[i];
                            s1[len/2-1]-=1;
                            string s2=s1;
                            reverse(s2.begin(),s2.end());
                            s1+=s2;
                            str[cnt++]=s1;
                            //cout<<s1<<endl;
                            s=sub(s,s1);
                        }
                    }
                }
                else
                {
                    if(len&1)
                    {
                        for(int i=0; i<=len/2; i++)
                            s1+=s[i];
                        s1=sub(s1,"1");
                        string s2="";
                        for(int i=s1.length()-2; i>=0; i--)
                            s2+=s1[i];
                        s1+=s2;
                        str[cnt++]=s1;
                        //cout<<s1<<endl;
                        s=sub(s,s1);
                    }
                    else
                    {
                        for(int i=0; i<len/2; i++)
                            s1+=s[i];
                        s1=sub(s1,"1");
                        string s2=s1;
                        reverse(s2.begin(),s2.end());
                        s1+=s2;
                        str[cnt++]=s1;
                        //cout<<s1<<endl;
                        s=sub(s,s1);
                    }
                }
                len=s.length();
            }
            calc(s);
        }
        cout<<cnt<<endl;
        for(int i=0; i<cnt; i++)
            cout<<str[i]<<endl;
    }
    return 0;
}
