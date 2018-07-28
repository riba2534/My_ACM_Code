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
const int N=10000+5;
int main()
{

    char s[20],maxx;
    int len;
    while(~scanf("%s",s))
    {
        len=strlen(s);
        maxx=s[0];
        for(int i=1; i<len; i++)
        {
            if(maxx<s[i])
                maxx=s[i];
        }
        printf("%c\n",maxx);
        mem(s,0);
    }
    return 0;
}
