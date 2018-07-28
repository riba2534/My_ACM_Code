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
int main()
{
    string s;
    cin>>s;
    int a=0,b=0,c=0,d=0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='(')
        {
            a++;
            d++;
        }
        if(s[i]==')')
        {
            b++;
            if(d)d--;
        }
        if(s[i]=='#')
        {
            c++;
            d=0;
        }
        if(b+c>a)
        {
            puts("-1");
            return 0;
        }
    }
    if(d>0)
    {
        puts("-1");
        return 0;
    }
    //cout<<a<<" "<<b<<" "<<c<<endl;
    int sum=a-b;
    if((sum==0&&c>0)||sum<c)
    {
        puts("-1");
        return 0;
    }
    for(int i=1; i<c; i++)
    {
        printf("1\n");
        sum--;
    }
    printf("%d\n",sum);

    return 0;
}
