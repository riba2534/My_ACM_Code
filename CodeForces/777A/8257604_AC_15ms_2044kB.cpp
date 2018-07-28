#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 200+20
#define M 100000+20
#define inf 0x3f3f3f3f
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(n==1)
    {
        if(m==1)
            printf("0\n");
        else if(m==0)
            printf("1\n");
        else if(m==2)
            printf("2\n");
    }
    else if(n>1)
    {
        int t=n%6;
        if(t==0)
        {
            if(m==0)printf("0\n");
            if(m==1)printf("1\n");
            if(m==2)printf("2\n");
        }
        if(t==1)
        {
            if(m==0)printf("1\n");
            if(m==1)printf("0\n");
            if(m==2)printf("2\n");
        }
        if(t==2)
        {
            if(m==0)printf("1\n");
            if(m==1)printf("2\n");
            if(m==2)printf("0\n");
        }
        if(t==3)
        {
            if(m==0)printf("2\n");
            if(m==1)printf("1\n");
            if(m==2)printf("0\n");
        }
        if(t==4)
        {
            if(m==0)printf("2\n");
            if(m==1)printf("0\n");
            if(m==2)printf("1\n");
        }
        if(t==5)
        {
            if(m==0)printf("0\n");
            if(m==1)printf("2\n");
            if(m==2)printf("1\n");
        }
    }
    return 0;
}