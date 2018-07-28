#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pir pair<int,int>
#define lson l,m,rt<<   1
#define rson m+1,r,rt<<1|1
typedef long long ll;
const int N=60+20;
char s[100];
int a[100];
int main()
{
    while(gets(s))
    {
        if(strcmp(s,"0000 0000 0000 0000")==0)
            break;
        for(int i=0; i<=3; i++)
            a[i+1]=s[i]-'0';
        for(int i=5; i<=8; i++)
            a[i]=s[i]-'0';
        for(int i=10; i<=13; i++)
            a[i-1]=s[i]-'0';
        for(int i=15; i<=18; i++)
            a[i-2]=s[i]-'0';
        //-----------------------------
        for(int i=1; i<=16; i++)
        {
            if(i&1)
            {
                a[i]*=2;
                if(a[i]>9)
                    a[i]-=9;
            }
        }
        int ans=0;
        for(int i=1; i<=16; i++)
        {
            ans+=a[i];
        }
        if(ans%10==0)
            puts("Yes");
        else
            puts("No");
        //printf("ans=%d\n",ans);



    }


    return 0;
}
