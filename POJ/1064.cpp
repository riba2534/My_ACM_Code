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
int calc(double x,int n)//���㵱��x���и�ʱ�����и�ɶ��ٸ���
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
        if(sum*100<k)//��Ϊ���������λС������������и��sum*100��0.01�׵���
        {
            cout<<"0.00"<<endl;
        }
        else
        {
            int  left=0,right=mx*100,ss;
            while(right>=left)//���ַ�
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
            ans=right/100.0;//����Ҫ��ϸ����
            printf("%.2lf\n",ans);
        }

    }
}
