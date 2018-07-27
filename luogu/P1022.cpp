#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define inf 1000000
#define mem(a,b) memset(a,b,sizeof(a))
const int N=100000+7;
int ans1=0,ans2=0;
char cc;
int is_num(char c)
{
    if(c>='0'&&c<='9')
        return 1;
    return 0;
}
int is_x(char c)
{
    if(c>='a'&&c<='z')
        return 1;
    return 0;
}
int mix_x(string s)
{
    int sum=0;
    int len=s.length();
    for(int i=0; i<len; i++)
        if(s[i]>='a'&&s[i]<='z')
        {
            cc=s[i];
            if(i==0)
            {
                sum++;
            }
            else if(i-1>=0&&s[i-1]=='+')
            {
                sum++;
            }
            else if(i-1>=0&&s[i-1]=='-')
            {
                sum--;
            }
            else
            {
                string num="";
                int flag=0;
                for(int j=i-1; j>=0; j--)
                {
                    if(s[j]=='+')
                    {
                        flag=1;
                        break;
                    }
                    if(s[j]=='-')
                    {
                        flag=2;
                        break;
                    }
                    num+=s[j];
                }
                reverse(num.begin(),num.end());
                if(flag==1||flag==0)
                {
                    sum+=atoi(num.c_str());
                }
                else if(flag==2)
                {
                    sum-=atoi(num.c_str());
                }
            }
        }
    return sum;
}
int mix_num(string s)
{
    int len=s.length();
    int sum=0;
    for(int i=0; i<len; i++)
    {
        int flag=0,flog=0;
        string num="";
        int j=i;
        if(is_num(s[i]))
        {
            if(i-1>=0&&s[i-1]=='-')
            {
                flog=1;
            }
            for(; j<len; j++)
            {
                if(is_x(s[j]))
                {
                    flag=1;
                    break;
                }
                if(s[j]=='+'||s[j]=='-')
                {
                    flag=2;
                    break;
                }
                num+=s[j];
            }
            // reverse(num.begin(),num.end());
            if(flag==1)
            {
                i=j;
                continue;
            }
            else if(flag==2)
            {
                if(flog)
                    sum-=atoi(num.c_str());
                else
                    sum+=atoi(num.c_str());
                i=j;
            }
            else if(flag==0&&flog==0)
            {
                sum+=atoi(num.c_str());
                i=j;
            }
            else if(flag==0&&flog==1)
            {
                sum-=atoi(num.c_str());
                i=j;
            }
        }
    }
    return sum;
}
int main()
{

    string s;
    cin>>s;
    int len=s.length();
    int pos=s.find("=");
    string s1=s.substr(0,pos);
    string s2=s.substr(pos+1,len-pos);
    int left_x=mix_x(s1);
    int right_x=mix_x(s2);
    int ans_x=left_x+(-1)*right_x;
    int left_num=mix_num(s1);
    int right_num=mix_num(s2);
    int ans_num=right_num+(-1)*left_num;
   // printf("l_num=%d,r_num=%d\n",left_num,right_num);
   // cout<<ans_x<<"   "<<ans_num<<endl;
    printf("%c=%.3lf\n",cc,(double)((ans_num*1.0)/(ans_x*1.0)));
    return 0;
}
