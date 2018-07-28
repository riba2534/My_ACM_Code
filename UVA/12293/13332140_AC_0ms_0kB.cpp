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
#define inf 0x3f3f3f3f
typedef long long ll;
#define mod 10000
const int N=500+20;
int x,k;
int main()
{
    while(cin>>x&&x)
    {
        int flag=1;
        while(x!=0)
        {
            if((x-1)%2)
            {
                flag=0;
                break;
            }
            x=(x-1)/2;
        }
        if(flag)puts("Bob");
        else puts("Alice");
    }
    return 0;
}
