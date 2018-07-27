#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include<list>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
const int N=1e6+10;
const int M=N*N;
char s[N];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        int len=strlen(s),pos=-1;
        for(int i=len-1; i>=0; i--)
        {
            if(s[i]!='0')
            {
                s[i]--;
                pos=i-1;
                break;
            }
        }
        for(;pos>=0;pos--)
        {
            if(s[pos]!='9')
            {
                s[pos]++;
                //sort(s+i,s+len);
                break;
            }
        }
        if(pos<0)printf("1");
        sort(s+pos+1,s+len);
        printf("%s\n",s);
    }
    return 0;
}