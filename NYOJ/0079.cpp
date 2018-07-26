 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[100];
        int num[100];
        mem(a,0);
        mem(num,0);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        int sum=0;
        num[0]=1;
        for(int i=1; i<n; i++)
        {
            int flag=0;
            for(int j=0; j<i; j++)
            {
                if(a[i]<a[j]&&flag<num[j])
                    flag=num[j];
            }
            num[i]=flag+1;
        }
        for(int i=0; i<n; i++)
        {
            sum=max(sum,num[i]);
        }
        printf("%d\n",sum);

    }
//    int n;
//    char str[10005];//存储字符串
//    int num[10005];//当前元素作为最大元素的最长递增序列
//    scanf("%d",&n);
//    while(n--)
//    {
//        mem(str,'\0');
//        mem(num,0);//初始化str和num
//        int sum=0;
//        num[0]=1;//第一个元素的最长递增序列一定为1
//        scanf("%s",str);
//        int len=strlen(str);
//
//        for(int i=1; i<len; i++)
//        {
//            int flag=0;//代表num[i]的值
//            for(int j=0; j<i; j++)
//            {
//                if(str[i]>str[j]&&flag<num[j])//把当前的第i个元素和前面的每一个元素比较&&递增序列必须连续递增
//                {
//                    flag=num[j];//更新序列长度
//                }
//            }
//            num[i]=flag+1;
//        }
//        for(int i=0; i<len; i++)
//        {
//            sum=max(sum,num[i]);//找出里面最大的长度
//        }
//        printf("%d\n",sum);
//    }
    return 0;
}
        