#include<bits/stdc++.h>  
#define mem(a,b) memset(a,b,sizeof(a))  
using namespace std;  
int day(int y,int m,int d)  
{  
    if(m==1||m==2)  
    {  
        m+=12;  
        y-=1;  
    }  
    int w=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1)%7;  
    return w;  
}  
int runnian(int a)  
{  
    if((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)  
        return 1;  
    else  
        return 0;  
}  
int main()  
{  
    int t,d,m,y;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d-%d-%d",&y,&m,&d);  
        int flag=0;  
        if(m==2&&d==29)  
            if(runnian(y))  
                flag=1;  
        int x=day(y,m,d);  
        for(int i=y+1; i<=10000; i++)  
        {  
            if(flag)  
            {  
                if(day(i,m,d)==x&&runnian(i))  
                {  
                    printf("%d\n",i);  
                    break;  
                }  
            }  
            else  
            {  
                if(day(i,m,d)==x)  
                {  
                    printf("%d\n",i);  
                    break;  
                }  
            }  
        }  
    }  
    return 0;  
}  