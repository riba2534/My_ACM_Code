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
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
const int N=1000+20;
int main()
{
    int n,j;
    string s;
    cin>>n>>s;
    s="$"+s;
    for(int i=1; i<=n; i++)
    {
        if(s[i]=='o'&&s[i+1]=='g'&&s[i+2]=='o')
        {
            printf("***");
            i+=2;
            j=i+1;
            while(s[j]=='g'&&s[j+1]=='o')
            {
                i+=2;
                j+=2;
            }
        }
        else
            cout<<s[i];
    }
    return 0;
}
