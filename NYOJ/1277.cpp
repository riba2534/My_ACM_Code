 
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
#define N 10000+20
#define M 1000000+10
#define ll long long
using namespace std;
int a[200],b[100];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s1[100],s2[100];
        mem(a,0);
        mem(b,0);
        scanf("%s%s",s1,s2);
        int len1=strlen(s1);
        int len2=strlen(s2);
        for(int i=0; i<len1; i++)
        {
            s1[i]=(s1[i]-'0'+1)%2+'0';
            for(int j=len1-1; j>=0; j--)
                a[i]+=(s1[j]-'0')*(int)pow(2,len1-1-j);
            s1[i]=(s1[i]-'0'+1)%2+'0';
        }
        int k=0;
        for(int i=0; i<len2; i++,k++)
        {
            s2[i]=(s2[i]-'0'+1)%3+'0';
            for(int j=len2-1; j>=0; j--)
                b[k]+=(s2[j]-'0')*(int)pow(3,len2-1-j);
            k++;
            s2[i]=(s2[i]-'0'+1)%3+'0';
            for(int j=len2-1; j>=0; j--)
                b[k]+=(s2[j]-'0')*(int)pow(3,len2-1-j);
            s2[i]=(s2[i]-'0'+1)%3+'0';
        }
        int flag=0;
        for(int i=0;i<len1;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(a[i]==b[j])
                {
                    printf("%d\n",a[i]);
                    flag=1;
                    break;
                }
            }
            if(flag)break;
        }
    }
    return 0;
}










        