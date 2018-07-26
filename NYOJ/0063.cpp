 
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define debug() puts("what the fuck!!!")
#define ll long long
using namespace std;
const int N=21;
int s[1<<N];
int main()
{
    int d,i;
    while(scanf("%d%d",&d,&i)&&(d||i))
    {
        mem(s,0);
        int n=(1<<d)-1,k;
        while(i--)
        {
            k=1;
            while(1)
            {
                s[k]=!s[k];
                if(s[k])
                    k=k<<1;
                else
                    k=k<<1|1;
                if(k>n) break;
            }

        }
        printf("%d\n",k/2);
    }
    return 0;
}

        