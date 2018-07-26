 
#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define inf 0x3f3f3f3f
typedef long long ll;
const int N = 1000 + 20;
stack<char> st_ch;
stack<double> st_num;
void calc1()
{
    char ch = st_ch.top();
    while (ch != '(')
    {
        double num1 = st_num.top();
        st_num.pop();
        double num2 = st_num.top();
        st_num.pop();
        switch (ch)
        {
        case '+':
            num2 += num1;
            break;
        case '-':
            num2 -= num1;
            break;
        case '*':
            num2 *= num1;
            break;
        case '/':
            num2 /= num1;
            break;
        }
        st_num.push(num2);
        st_ch.pop();
        ch = st_ch.top();
    }
}
void calc2()
{
    char ch = st_ch.top();
    while (ch == '*' || ch == '/')
    {
        double num1 = st_num.top();
        st_num.pop();
        double num2 = st_num.top();
        st_num.pop();
        switch (ch)
        {
        case '*':
            num2 *= num1;
            break;
        case '/':
            num2 /= num1;
            break;
        }
        st_num.push(num2);
        st_ch.pop();
        ch = st_ch.top();
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    string str;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> str;
        int len = str.size();
        st_ch.push('(');
        string str_num = "";
        for (int i = 0; i < len; i++)
        {
            if (isdigit(str[i]) || str[i] == '.')
            {
                str_num += str[i];
                continue;
            }
            if (str_num != "")
            {
                double num = atof(str_num.c_str());
                st_num.push(num);
                str_num = "";
            }
            switch (str[i])
            {
            case '+':
            case '-':
                calc1();
                st_ch.push(str[i]);
                break;
            case '*':
            case '/':
                calc2();
                st_ch.push(str[i]);
                break;
            case '(':
                st_ch.push('(');
                break;
            case ')':
            case '=':
                calc1();
                st_ch.pop();
                break;
            }
        }
        printf("%.2lf\n", st_num.top());
        st_num.pop();
    }
    return 0;
}        