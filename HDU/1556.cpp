#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N 100000+20
#define M 1000000+10
#define ll long long
using namespace std;
int c[N];
int lowbit(int x)//用来维护树状数组,得到管辖区间
{
    return x&-x;
}
void add(int k,int num,int n)//给数组的第k位增加num个
{
    while(k<=n)
    {
        c[k]+=num;
        k+=lowbit(k);
    }
}
int sum(int n)//求要查询的区间的前n项和
{
    int sum=0;
    while(n>0)
    {
        sum+=c[n];
        n-=lowbit(n);
    }
    return sum;
}
int main()
{
    int n,a,b;
    while(scanf("%d",&n)&&n)
    {
        mem(c,0);
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&a,&b);
            add(a,1,n);
            add(b+1,-1,n);//主要是这里，向上统计，向下修改
        }
        for(int i=1; i<=n; i++)
        {
            if(i>1)printf(" ");
            printf("%d",sum(i));
        }
        puts("");
    }
    return 0;
}

//#include <cstdio>
//#include <cstring>
//#include <cctype>
//#include <string>
//#include <set>
//#include <iostream>
//#include <stack>
//#include <cmath>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#define mem(a,b) memset(a,b,sizeof(a))
//#define inf 0x3f3f3f3f
//#define mod 10000007
//#define debug() puts("what the fuck!!!")
//#define N 100000+20
//#define M 1000000+10
//#define ll long long
//using namespace std;
//int c[N];
//int main()
//{
//    int n,a,b;
//    while(scanf("%d",&n)&&n)
//    {
//        mem(c,0);
//        for(int i=1; i<=n; i++)
//        {
//            scanf("%d%d",&a,&b);
//            c[a]++;
//            c[b+1]--;
//        }
//        int ans=0;
//        for(int i=1; i<=n; i++)
//        {
//            if(i>1)printf(" ");
//            ans+=c[i];
//            printf("%d",ans);
//        }
//        puts("");
//    }
//    return 0;
//}
