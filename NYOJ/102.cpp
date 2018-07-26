 
#include <stdio.h>
long long pow_mod(long long a, long long b, long long c)
{
    long long ans = 1;
    a = a % c;
    while(b>0)
    {
        if(b % 2==1)
            ans = (ans * a) % c;
        b = b/2;
        a = (a * a) % c;
    }
    return ans;
}
//long long pow_mod1(long long a,long long b,long long c)
//{
//    long long s=1;
//    a=a%c;
//    while(b!=0)
//    {
//        if(b&1)
//            s=s*a%c;
//        a=a*a%c;
//        b>>=1;
//    }
//    return s;
//}
int main()
{
    long long t;
    scanf("%lld",&t);
    while(t--)
    {
        long long a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        printf("%lld\n",(pow_mod(a,b,c)+c)%c);
    }
    return 0;
}
        