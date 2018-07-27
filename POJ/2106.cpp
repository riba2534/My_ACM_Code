#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 1000+10
#define M 1000000+10
#define LL long long
using namespace std;
char s[100];
stack<bool>num;
stack<char>chars;
char to_char(bool x)
{
    if(x)
        return 'V';
    else
        return 'F';
}
bool to_int(char c)
{
    if(c=='V')
        return 1;
    else
        return 0;
}
void deal_int(char c)
{
    if(c==')')
        chars.pop();
    else
        num.push(to_int(c));
    if(chars.empty()||chars.top()=='(')
        return;
    bool t_num;
    while(!chars.empty()&&!num.empty()&&chars.top()!='(')
    {
        if(chars.top()=='!')//‘!’取值的时候不需要num中的符号大于1，！可以直接运算
        {
            if(!chars.empty())
            {
                t_num=(!num.top());
                num.pop();
                chars.pop();
                num.push(t_num);
            }
            else
                break;
        }
        else if(chars.top()=='&'&&num.size()>1)
        {
            if(num.size()>1)
            {
                t_num=num.top();
                num.pop();
                chars.pop();
                t_num=(num.top()&&t_num);
                num.pop();
                num.push(t_num);

            }
            else
                break;

        }
        else if(chars.top()=='|'&&num.size()>1)
        {

            if(num.size()>1)
            {
                t_num=num.top();
                num.pop();
                chars.pop();
                t_num=(num.top()||t_num);
                num.pop();
                num.push(t_num);
            }
            else
                break;
        }
    }
    return;

}
int solve()
{
    while(!num.empty())num.pop();
    while(!chars.empty())chars.pop();
    int len=strlen(s);
    for(int i=0; i<len; i++)
    {
        if(s[i]==' ')
            continue;
        if(s[i]==')'||s[i]=='F'||s[i]=='V')
            deal_int(s[i]);
        else
            chars.push(s[i]);
    }
    return to_char(num.top());
}
int main()
{
    int q=1;
    while(gets(s))
    {
        printf("Expression %d: %c\n",q++,solve());
    }

    return 0;
}
