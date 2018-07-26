 
//#include<cstdio>
//#include<cstring>
//#include<cctype>
//#include<string>
//#include<set>
//#include<iostream>
//#include<stack>
//#include<cmath>
//#include<queue>
//#include<vector>
//#include<algorithm>
//#define mem(a,b) memset(a,b,sizeof(a))
//#define inf 0x3f3f3f3f
//#define mod 10000007
//#define debug() puts("whatthefuck!!!")
//#define N 1111111
//#define M 1000000
//#define ll longlong
//using namespace std;
//char s1[100],s2[100];
//int vis[100];
//int n,ans;
//int calc(int t)
//{
//    int sum_a=0,sum_b=0;
//    strcpy(s2+1,s1+1);
//    while(t)
//    {
//        for(int i=1; i<=t; i++)
//        {
//            if(s2[i]=='+')sum_a++;
//            if(s2[i]=='-')sum_b++;
//        }
//        for(int i=1; i<=t-1; i++)
//        {
//            if(s2[i]==s2[i+1])
//                s2[i]='-';
//            else
//                s2[i]='+';
//        }
//        t--;
//    }
//    if(sum_a==sum_b)
//        return 1;
//    return 0;
//}
//void dfs(int cnt)
//{
//    if(cnt==n+1)//构造成符合条件的序列
//    {
//        if(calc(n))
//            ans++;//计算有几种情况
//        return;
//    }
//    if(!vis[cnt])//构造序列
//    {
//        vis[cnt]=1;
//        s1[cnt]='+';
//        dfs(cnt+1);
//        s1[cnt]='-';
//        dfs(cnt+1);
//        vis[cnt]=0;
//    }
//}
//int main()
//{
//    for(int i=1; i<20; i++)
//    {
//        mem(vis,0);
//        ans=0;
//        n=i;
//        dfs(1);
//        printf("%d,",ans);
//    }
//    return 0;
//}
#include <stdio.h>
int a[20]={0,0,4,6,0,0,12,40,0,0,171,410,0,0,1896,5160,0,0,32757};
int main()
{
    int n;
    while(~scanf("%d",&n))
        printf("%d\n",a[n-1]);
}
        