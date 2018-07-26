 
#include <bits/stdc++.h>
using namespace std;
const int N=41;
char s[20];
int main()
{
    int t,n,m;
    scanf("%d",&t);
    string ss;
    while(t--)
    {
        map<string,int>mp;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            scanf("%s",s);
            ss=s;
            mp[ss]++;
        }
        while(m--)
        {
            scanf("%s",s);
            ss=s;
            printf("%d\n",mp[ss]);
        }
    }
    return 0;
}


        