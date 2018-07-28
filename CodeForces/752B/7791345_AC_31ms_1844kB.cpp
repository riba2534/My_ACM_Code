//#include <stdio.h>
//#include <string.h>
//#include <iostream>
//#include <stack>
//#include <queue>
//#include <vector>
//#include <string>
//#include <algorithm>
//#define mem(a,b) memset(a,b,sizeof(a))
//using namespace std;
//int main()
//{
//    char a[1001];
//    char b[1001];
//    int flag=0;
//    scanf("%s%s",a,b);
//    int len=strlen(a);
//    if(strcmp(a,b)==0)
//        printf("0\n");
//    else
//    {
//        for(int i=0;i<len;i++)
//        {
//            if(a[i]!=b[i])
//            {
//                for(int j=i;j<len;j++)
//                {
//                    char s=b[j];
//                    a[j]=b[j];
//                    for(int k=i;k<len;k++)
//                    {
//
//                    }
//                }
//            }
//        }
//
//
//
//    }
//
//    return 0;
//}
//
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s1[1010],s2[1010],f[500];
int main()
{
    int i,j,k,l,p,q,x,y,z,ans;
    scanf("%s%s",s1,s2);
    l=strlen(s1);
    for (i=0; i<l; i++)
        if (f[s1[i]]*f[s2[i]]==0)
        {
            if (f[s1[i]]+f[s2[i]]==0)
            {
                f[s1[i]]=s2[i];
                f[s2[i]]=s1[i];
            }
            else
            {
                printf("-1\n");
                return 0;
            }
        }
        else
        {
            if (f[s1[i]]!=s2[i]||f[s2[i]]!=s1[i])
            {
                printf("-1\n");
                return 0;
            }
        }
    ans=0;
    for (i='a'; i<='z'; i++)
        if (f[i]&&f[i]>i) ans++;
    printf("%d\n",ans);
    for (i='a'; i<='z'; i++)
        if (f[i]&&f[i]>i) printf("%c %c\n",i,f[i]);
}
