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
#define N 20000+20
#define mod 10007
#define M 1000000+10
#define LL long long
using namespace std;
char map[100][100];
int main()
{
    string s="";
    int n;
   cin>>n;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4*n;j++)
        {
            cin>>map[i][j];
        }
    }
    int i,j;
    for(i=0;i<4*n;i+=4)
    {
        //for( j=i;j<4;j++)
       // {
          //  printf("i=%d,j=%d\n",i,j);
           if(map[3][i+1]=='*')
            s+="1";
           if(map[3][i]=='*')
            s+="2";
           if(map[3][i+2]=='*')
            s+="3";

       // }
    }
    cout<<s;
    return 0;
}
