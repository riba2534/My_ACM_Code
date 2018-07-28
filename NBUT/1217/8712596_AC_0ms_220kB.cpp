#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 1000+20
#define mod 10007
#define M 1000000+10
#define LL long long
using namespace std;
string s;
int main()
{
    int n;
    while(cin>>n)
    {
        int flag=0,i;
        for(i=1; i<=n; i++)
        {
            cin>>s;
            if(s=="bowl"||s=="knife"||s=="fork"||s=="chopsticks")
            {
                if(flag)
                    cout<<" ";
                cout<<s;
                flag=1;
            }
        }
        printf("\n");
    }
    return 0;
}
