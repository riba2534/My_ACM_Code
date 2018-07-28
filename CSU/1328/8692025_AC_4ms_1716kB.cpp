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
char s[2500];
char buf[2500];
int p[2500];
int main()
{
    int k,x,y,i,j,q=1;
    while(~scanf("%d",&k))
    {
        getchar();
        gets(buf);
        int maxx=0,n,m=0,star=-1,cnt;
        n=strlen(buf);
        for(i=0; i<n; i++)
        {
            if(isalpha(buf[i]))
            {
                p[m]=i;//记录原先的位置
                s[m++]=toupper(buf[i]);//转换成小写
            }
        }
        for(i=0; i<m; i++)//枚举中间的位置
        {
            cnt=0;
            for(j=0; i-j>=0&&i+j<m; j++)//长度为奇数
            {
                if(s[i-j]!=s[i+j])
                    cnt++;
                if(cnt>k)
                    break;
            }
            j--;
            x=p[i-j],y=p[i+j];//x和y代表区间的首尾
            if(y-x+1>maxx)//更新最大值和x的位置
            {
                maxx=y-x+1;
                star=x;
            }
            cnt=0;
            for(j=0; i-j>=0&&i+j+1<m; j++)//长度为偶数
            {
                if(s[i-j]!=s[i+j+1])
                    cnt++;
                if(cnt>k)
                    break;
            }
            j--;
            if(j<0)continue;
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

