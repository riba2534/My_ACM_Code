//#include <cstdio>
//#include <cstring>
//#include <cctype>
//#include <string>
//#include <iostream>
//#include <stack>
//#include <cmath>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#define mem(a,b) memset(a,b,sizeof(a))
//#define inf 0x3f3f3f3f
//#define N 100000+20
//#define mod 10007
//#define M 1000000+10
//#define LL long long
//using namespace std;
//char s[2500];
//char buf[2500];
//int judge(int i,int j,int n)
//{
//    int ok=0;
//    for(int k=i;i<=j;i++)
//    {
//        if(buf[k]!=buf[i+j-k])
//        {
//            ok++;
//            if(ok>=n)
//                return 0;
//        }
//    }
//    return 1;
//
//}
//int main()
//{
//    int k;
//    while(~scanf("%d",&k))
//    {
//        getchar();
//        gets(s);
//        int maxx=0,m=0;
//        int len=strlen(s);
//        for(int i=0;i<len;i++)
//        {
//            if(isalpha(s[i]))
//                buf[m++]=toupper(s[i]);
//        }
//        for(int i=0;i<m;i++)
//        {
//            for(int j=i;j<m;j++)
//            {
//                if(judge(i,j,k)&&j-i+1>maxx)
//                    maxx=j-i+1;
//            }
//        }
//       printf("%d\n",maxx);
//    }
//    return 0;
//}

#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 100000+20
#define mod 10007
#define M 1000000+10
#define LL long long
using namespace std;
char buf[2500],s[2500];
int p[2500];

int main()
{
    int i,j,q=1,k;
    while(~scanf("%d",&k))
    {
        getchar();
        int n,m=0,maxx=0,x,y,cnt,star=-1;
        gets(buf);
        n=strlen(buf);
        for(i=0; i<n; i++)//对字符串进行预处理，使之转化为只有小写字母
            if(isalpha(buf[i]))
            {
                p[m]=i;//记录原先的位置
                s[m++]=tolower(buf[i]);
            }
        for(i=0; i<m; i++) //枚举回文串的“中间”位置
        {
            for(cnt=j=0; i-j>=0&&i+j<m; j++) //长度为奇数
            {

                if(s[i-j]!=s[i+j])
                    cnt++;
                if(cnt>k)
                    break;
            }
            j--;
            // printf("i=%d,j=%d\n",i,j);
            x=p[i-j],y=p[i+j];
            if(y-x+1>maxx)
            {
                maxx=y-x+1;
                star=x;
            }

            for(cnt=j=0; i-j>=0&&i+j+1<m; j++) //长度为偶数
            {
                if(s[i-j]!=s[i+j+1])
                    cnt++;
                if(cnt>k)
                    break;
            }
            j--;
            if(j<=-1)//排除异常情况
                continue;
            x=p[i-j],y=p[i+j+1];
            if(y-x+1>maxx)
            {
                maxx=y-x+1;
                star=x;
            }

        }
        printf("Case %d: %d %d\n",q++,maxx,star+1);
    }
    return 0;
}
