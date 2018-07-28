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
char s[10];
double change(char c)
{
    if(c>='0'&&c<='9')
        return c-'0';
    return c-'a'+10;
}
char slove(char c1,char c2)
{
    double ans=change(c1)*16+change(c2);
    //cout<<ans<<endl;
    int res=(int)(ans/17+0.5);
    return res<10?res+'0':res+'a'-10;
}
int main()
{
    scanf("%s",s);
    printf("#%c%c%c\n",slove(s[1],s[2]),slove(s[3],s[4]),slove(s[5],s[6]));
    return 0;
}
