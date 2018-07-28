#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
const int N=1e3+20;
int main()
{
    string s;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        int sum=0,cnt=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='O')
                sum+=++cnt;
            else
                cnt=0;
        }
        cout<<sum<<endl;
    }
    return 0;
}
