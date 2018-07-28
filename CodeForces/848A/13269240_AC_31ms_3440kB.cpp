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
#define mod 1000000009
typedef long long ll;
const int N=105+20;
int main()
{
    int n;
    char c='a';
    int k=0;
    scanf("%d",&n);
    if(n==0)
    {
        puts("a");
    }
    else
    {
        while(n)
        {
            while(1)
            {
                if(n-k>=0)
                {
                    n-=k;
                    printf("%c",c);
                    k++;
                }
                else
                    break;

            }
            c++;
            k=0;
        }
    }

    return 0;
}


