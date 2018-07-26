 
#include <stdio.h>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int cifang(int a,int b)
{
    int c=a;
    if(b==0)
        return 1;
    else
    {
        for(int i=b; i>1; i--)
        {
            a*=c;
        }
        return a;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char a[40];
        int b=0,c=3,d=0,k=1,l=0;
        scanf("%d",&l);
        while(l!=6174)
        {
            sprintf(a,"%d",l);
            //从大到小 ,获得b
            sort(a,a+4,cmp);
            for(int i=0; i<4; i++)
            {
                b+=(a[i]-'0')*cifang(10,c);
                c--;
            }
            //从小到大,获得d
            sort(a,a+4);
            c=3;
            for(int i=0; i<4; i++)
            {
                d+=(a[i]-'0')*cifang(10,c);
                c--;
            }
              l=b-d;
            //变量初始化
            k++;
            b=0;
            c=3;
            d=0;
        }
        printf("%d\n",k);
    }
    return 0;
}
        