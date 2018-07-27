#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<iostream>
#include <cmath>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N (1010)
#define ll long long
using namespace std;
string div(string str,int x)
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

    if(y)ans=str;
    return ans;
}
int main()
{
    string s;
    while(cin>>s)
    {
        if(s=="-1")return 0;
        if(s.length()==1)
            cout<<"1"<<s<<endl;
        else
        {
            string ans="",ss=s;//ss是原字符串的复制
            for(int i=9; i>0; i--)
            {
                while(ss.length()!=1)//判断一个数字能不能连续除
                {
                    string qq=div(ss,i);//临时保存计算结果
                    if(qq==ss)//当有余数的时候
                        break;
                    else
                    {
                        ans+=(i+'0');
                        ss=qq;
                    }
                }
            }
            if(ss.length()==1)
            {
                ans+=ss;
                reverse(ans.begin(),ans.end());
                cout<<ans<<endl;
            }
            else
                puts("There is no such number.");
        }
    }
    return 0;
}




