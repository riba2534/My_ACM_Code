#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
typedef long long ll;
const int N=1000+20;
int main()
{
    string s1,s2;
    int sum=0,t1,t2;
    cin>>s1>>s2;
    int len1=s1.size();
    int len2=s2.size();
    for(int i=0; i<len1; i++)
    {
        if(s1[i]!=s2[i])
        {
            sum++;
            if(sum==1)t1=i;
            if(sum==2)t2=i;
        }
    }
    if(len1==len2&&sum==2&&s1[t1]==s2[t2]&&s1[t2]==s2[t1])
        puts("YES");
    else
        puts("NO");
    return 0;
}
