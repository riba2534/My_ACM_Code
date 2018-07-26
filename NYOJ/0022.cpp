 
//#include<cstdio>
//#include<cstring>
//#include<string>
//#include<set>
//#include <map>
//#include<iostream>
//#include <cmath>
//#include<stack>
//#include<queue>
//#include<vector>
//#include<algorithm>
//#define mem(a,b) memset(a,b,sizeof(a))
//#define inf 0x3f3f3f3f
//#define mod 10000007
//#define debug() puts("what the fuck!!!")
//#define N (1000020)
//#define ll long long
//using namespace std;
//int a[1010];
//int sushu(int n)
//{
//    int flag=1;
//    if(n==0||n==1)
//        flag=0;
//    for(int i=2; i<=sqrt(n); i++)
//    {
//        if(n%i==0)
//        {
//            flag=0;
//            break;
//        }
//    }
//    return flag;
//}
//int main()
//{
//    int t,m,n;
//    scanf("%d",&t);
//    while(t--)
//    {
//        scanf("%d",&n);
//        for(int i=0; i<n; i++)
//            scanf("%d",&a[i]);
//
//    }
//
//    return 0;
//}
//
//

#include<stdio.h>
#include <math.h>
int a[1001];
int sushu(int n)
{
	int flag=1,i;
	if(n==0||n==1)
	{
		flag=0;
	}
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			flag=0;
			break;
		}
	}
	return flag;
}
int main()
{
	int t,n,i,f;
	scanf("%d",&t);
	while(t--)
	{
		int m=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			f=sushu(a[i]);
			if(f==1)
				m+=a[i];
		}
		printf("%d\n",m);
	}
	return 0;
}

        