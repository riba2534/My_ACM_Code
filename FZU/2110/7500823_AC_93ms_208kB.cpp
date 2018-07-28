#include<string.h>
#include<stdio.h>
#include<math.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;//n组数据
        scanf("%d",&n);
        double num[2][105];//存储坐标
        for(int i=0; i<n; i++)
            scanf("%lf%lf",&num[0][i],&num[1][i]);//存储x，y坐标
        double a,b,c;//三角形三条边
        int sum=0;//记录总数
        int i,j,k;
        for(i=0; i<n-2; i++)
            for(j=i+1; j<n-1; j++)
                for(k=j+1; k<n; k++)
                {
                    a=sqrt((num[0][i]-num[0][j])*(num[0][i]-num[0][j])+(num[1][i]-num[1][j])*(num[1][i]-num[1][j]));
                    b=sqrt((num[0][i]-num[0][k])*(num[0][i]-num[0][k])+(num[1][i]-num[1][k])*(num[1][i]-num[1][k]));
                    c=sqrt((num[0][k]-num[0][j])*(num[0][k]-num[0][j])+(num[1][k]-num[1][j])*(num[1][k]-num[1][j]));
                    if(a*a+b*b>c*c&&a*a+c*c>b*b&&b*b+c*c>a*a)
                        sum++;
                }
        printf("%d\n",sum);
    }
    return 0;
}