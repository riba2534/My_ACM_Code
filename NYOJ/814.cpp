 
#include<stdio.h>
int main()
{
    int n,i,j,c,a[3000],q[3000];//q存导弹拦截系统
    while(1)
    {
        scanf("%d",&n);
        if(n==-1)return 0;
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);//输入导弹数据
        q[0]=a[0];//让拦截系统中第一个值等于第一个导弹飞来的高度
        c=1;//拦截系统的个数
        for(i=1; i<n; i++)
        {
            for(j=0; j<c; j++)//枚举当前导弹拦截系统的个数
                if(a[i]<=q[j])//如果小于前一个证明可以拦截
                {
                    q[j]=a[i];//更新拦截系统的值
                    break;
                }
            if(j>=c)//如果不能拦截
            {
                q[j]=a[i];//新的导弹系统的最大值
                c++;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
        