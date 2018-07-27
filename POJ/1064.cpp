//#include <stdio.h>
//#include <string.h>
//#include <string>
//#include <iostream>
//#include <stack>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#define mem(a,b) memset(a,b,sizeof(a))
//#define inf 0x3f3f3f3f
//#define N 1000+10
//#define LL long long
//using namespace std;
//double
//int main()
//{
//    int n,k;
//    scanf("%d%d",&n,&k);
//
//    return 0;
//}
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 1000+10
#define LL long long
using namespace std;
#define Max 10005
using namespace std;
double tlen[Max];
int calc(double x,int n)//计算当以x长切割时，能切割成多少根线
{
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum+=int(tlen[i]/x);
    }
    return sum;
}
int main()
{
    int n,k;
    double mx,mid,sum,ans;
    while(cin>>n>>k)
    {
        sum=0;
        for (int i=0; i<n; i++)
        {
            scanf("%lf",&tlen[i]);
            if(mx<tlen[i])
                mx=tlen[i];
            sum+=tlen[i];
        }

        int flg=0;
        if(sum*100<k)//因为结果保留两位小数，所以最多切割成sum*100根0.01米的线
        {
            cout<<"0.00"<<endl;
        }
        else
        {
            int  left=0,right=mx*100,ss;
            while(right>=left)//二分法
            {
                ss=(left+right)/2;
                mid=ss/100.0;
                if(calc(mid,n)<k)
                {
                    right=ss-1;
                }
                else
                    left=ss+1;
            }
            ans=right/100.0;//这里要仔细想想
            printf("%.2lf\n",ans);
        }

    }
}
