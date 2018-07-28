#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1000000+10;
ll t,n,q=1,tmp;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        printf("Case #%lld: ",q++);
        tmp=n;
        n=sqrt(n*2)+10;
        ll i;
        for(i=n; i>=1; i--)
            if(i*(i+1)/2<=tmp)
                break;
        cout<<i*(i+1)/2<<endl;
    }
    return 0;
}
