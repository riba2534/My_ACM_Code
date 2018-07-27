#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 100000+20
#define mod 10007
#define M 1000000+10
#define LL long long
using namespace std;
set<int>s;
int solve(int a,int b, int c)
{
    s.insert(a);
    s.insert(b);
    s.insert(c);
    if(b-a>=1)s.insert(b-a);
    if(a-b>=1)s.insert(a-b);
    if(c-a>=1)s.insert(c-a);
    if(a-c>=1)s.insert(a-c);
    if(b-c>=1)s.insert(b-c);
    if(c-b>=1)s.insert(c-b);
    s.insert(a+b);
    s.insert(b+c);
    s.insert(a+c);
    s.insert(a+b+c);
    if(c-a-b>=1)s.insert(c-a-b);
    if(b-a-c>=1)s.insert(b-a-c);
    if(a-b-c>=1)s.insert(a-b-c);
    if(c-b+a>=1)s.insert(c-b+a);
    if(c-a+b>=1)s.insert(c-a+b);
    if(a+b-c>=1)s.insert(a+b-c);
    if(a-b+c>=1)s.insert(a-b+c);
    if(b+a-c>=1)s.insert(b+a-c);
    if(b-a+c>=1)s.insert(b-a+c);
}
int main()
{
    int t,x,y;
    scanf("%d",&t);
    while(t--)
    {
        int sum=0;
        scanf("%d%d",&x,&y);
        for(int i=1; i<x; i++)
        {
            s.clear();
            int num=x-i;
            solve(i,num,y);
            if(s.size()>sum)
                sum=s.size();
        }
        for(int i=1; i<y; i++)
        {
            s.clear();
            int num=y-i;
            solve(i,num,x);
            if(s.size()>sum)
                sum=s.size();
        }
        printf("%d\n",sum);
    }
    return 0;
}