 
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
#define N 100100
#define M 1000000+10
#define ll long long
using namespace std;
char s[10000];
stack<int>num;
stack<char>ope;
char tchar;
int tnum,wei;
char getope(char a,char b)
{
    if(a=='a')
        return '+';
    if(a=='m'&&b=='a')
        return '>';
    else
        return '<';
}
int calc(int a,int b,char c)
{
    if(c=='>')
        return max(a,b);
    if(c=='<')
        return min(a,b);
    if(c=='+')
        return a+b;

}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        while(!ope.empty())ope.pop();
        while(!num.empty())num.pop();
        scanf("%s",s);
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            if(s[i]=='a'||s[i]=='m')
            {
                tchar=getope(s[i],s[i+1]);
                ope.push(tchar);
                i+=2;
            }
            else if(s[i]>='0'&&s[i]<='9')
            {
                sscanf(&s[i],"%d%n",&tnum,&wei);
                num.push(tnum);
                i+=wei-1;
            }
            else if(s[i]==')')
            {
                int b=num.top();
                num.pop();
                int a=num.top();
                num.pop();
                char c=ope.top();
                ope.pop();
                num.push(calc(a,b,c));
            }

        }
        printf("%d\n",num.top());
    }

    return 0;
}
        