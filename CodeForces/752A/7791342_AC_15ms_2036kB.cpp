#include <stdio.h>  
#include <string.h>  
#include <iostream>  
#include <stack>  
#include <queue>  
#include <vector>  
#include <algorithm>  
#define mem(a,b) memset(a,b,sizeof(a))  
using namespace std;  
int main()  
{  
    int n,m,k;  
    scanf("%d%d%d",&n,&m,&k);  
    if(k&1)  
    {  
        k++;  
        int shu=k/2;  
        int x,y;  
        if(shu%m==0)  
            x=shu/m;  
        else  
            x=shu/m+1;  
        if(shu%m==0)  
            y=m;  
        else  
            y=shu%m;  
        printf("%d %d L\n",x,y);  
    }  
    else  
    {  
        int shu=k/2;  
        int x,y;  
        if(shu%m==0)  
            x=shu/m;  
        else  
            x=shu/m+1;  
        if(shu%m==0)  
            y=m;  
        else  
            y=shu%m;  
        printf("%d %d R\n",x,y);  
    }  
  
    return 0;  
}  