 
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int N=1000+20;
int main()
{
    int t;
    string s1,s2,ans;
    scanf("%d",&t);
    while(t--)
    {
        cin>>s1;
        s2=s1;
        reverse(s2.begin(),s2.end());
        int maxx=0;
        int len=s1.size();
        for(int i=0; i<len; i++)
        {
            for(int j=1; j<=len-i; j++)
            {
                int pos=s2.find(s1.substr(i,j));
                if(pos!=string::npos&&maxx<j)
                {
                    maxx=j;
                    ans=s1.substr(i,j);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}        