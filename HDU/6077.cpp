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
#define N 300
#define ll long long
using namespace std;
char s[30][30];
int jc(int x1,int y1,int x2,int y2)
{
    int sum=0;
    int n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0;
    if(s[1][y1]=='X'&&s[2][y1]=='X') n2=1;
    if(s[4][y2]=='X'&&s[5][y2]=='X') n7=1;
    if(s[3][y1+1]=='X'&&s[3][y1+2]=='X') n4=1;
    if(s[1][y2]=='X'&&s[2][y2]=='X') n3=1;
    for(int i=x1; i<=x2; i++)
        for(int j=y1; j<=y2; j++)
            if(s[i][j]=='X')
                sum++;
    if(sum==4) return 1;
    else if(sum==8) return 4;
    else if(sum==6) return 7;
    else if(sum==14) return 8;
    else if(sum==12)
    {
        if(!n4)
            return 0;
        else if(n3)
            return 9;
        else
            return 6;
    }
    else if(sum==10)
    {
        if(n2)
            return 5;
        else if(n7)
            return 3;
        else
            return 2;
    }
}
int main()
{
    int t,a,b,c,d;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0; i<7; i++)
            scanf("%s",s[i]);
        a=jc(0,0,6,3);
        b=jc(0,5,6,8);
        c=jc(0,12,6,15);
        d=jc(0,17,6,20);
        printf("%d%d:%d%d\n",a,b,c,d);
    }
    return 0;
}
