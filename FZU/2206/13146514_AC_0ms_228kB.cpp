//#include <stdio.h>
//#include <iostream>
//#include <algorithm>
//#include <string.h>
//#include <string>
//using namespace std;
//typedef long long ll;
//#define inf 0x3f3f3f3f
//#define mem(a,b) memset(a,b,sizeof(a))
//const ll N=100+10;
//ll f(ll x)
//{
//    while(x>=20150001)
//    {
//        x-=2015;
//        while(x>=20150001)
//        {
//            x-=2015;
//            if(x<20150001)
//                x+=2014;
//        }
//        if(x<20150001)
//            x+=2014;
//    }
//    return x;
//}
//int main()
//{
//    ll t,n;
//    scanf("%lld",&t);
//    while(t--)
//    {
//        scanf("%lld",&n);
//        printf("%lld\n",f(n));
//    }
//
//    return 0;
//}
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
const int N=100+10;

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n<20150001)
            printf("%d\n",n+2014);
        else
            printf("20152014\n");

    }


    return 0;
}
