 
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
#define N 1000+20
#define M 1000000+10
#define ll long long
using namespace std;
stack<int>num;//数据栈
stack<char>tchar;//字符栈
char s[N];
int calc(int a,int b,char c)
{
    if(c=='+')return a+b;
    if(c=='-')return a-b;
    if(c=='*')return a*b;
    if(c=='/')return a/b;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        while(!num.empty())num.pop();
        while(!tchar.empty())tchar.pop();
        scanf("%s",s+1);
        int len=strlen(s+1);
        s[0]='(';
        s[++len]=')';
        for(int i=0; i<=len; i++)
        {
            if(s[i]=='(')
                tchar.push(s[i]);
            else if(s[i]=='S')
            {
                tchar.push('(');
                i+=3;
            }
            else if(s[i]>='0'&&s[i]<='9')
            {
                int fnum,fwei;
                sscanf(&s[i],"%d%n",&fnum,&fwei);

                i+=fwei-1;
                 //printf("fnum=%d,i=%d\n",fnum,i);
                num.push(fnum);

            }
            else if(s[i]=='+')
            {
                while(tchar.top()!='('&&tchar.top()!=',')
                {
                    int a=num.top();
                    num.pop();
                    int b=num.top();
                    num.pop();
                    int c=calc(a,b,tchar.top());

                    num.push(c);
                    tchar.pop();
                }
                tchar.push(s[i]);
            }
            else if(s[i]=='*')
            {
                if(tchar.top()=='*')
                {
                    int a=num.top();
                    num.pop();
                    int b=num.top();
                    num.pop();
                    num.push(a*b);
                    // printf("a*b=%d\n",a*b);
                    tchar.pop();
                }
                tchar.push(s[i]);
            }
            else if(s[i]==')'||s[i]==',')
            {
                while(tchar.top()!='(')
                {
                    int a=num.top();
                    num.pop();
                    int b=num.top();
                    num.pop();
                    int c,suma=0,sumb=0;
                    if(tchar.top()==',')
                    {
                        while(b!=0)
                        {
                            sumb+=b%10;
                            b/=10;
                        }
                        while(a!=0)
                        {
                            suma+=a%10;
                            a/=10;
                        }
                        c=max(suma,sumb);
                    }
                    else
                        c=calc(a,b,tchar.top());
                      //  printf("c=%d\n",c);
                    num.push(c);
                    tchar.pop();

                }
                tchar.pop();
                if(s[i]==',')
                    tchar.push(s[i]);
            }
        }
        printf("%d\n",num.top());
        num.pop();
    }
    return 0;
}
        