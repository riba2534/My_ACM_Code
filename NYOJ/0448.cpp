 
#include<stdio.h>  
#include<string.h>  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    while(t--)  
    {  
        char n[100];  
        int tempn[100];  
        int m,i,j,max=0,maxj=-1;  
        scanf("%s%d",n,&m);  
        memset(tempn,0,sizeof(tempn));  
        for(i=0; i<(strlen(n)-m); i++)  
        {  
            max=0;  
            for(j=maxj+1; j<=(m+i); j++)  
            {  
                if(tempn[j]==1)  
                    continue;  
                if(n[j]>max)  
                {  
                    max=n[j];  
                    maxj=j;  
                }  
            }  
            tempn[maxj]=1;  
        }  
        for(i=0; i<strlen(n); i++)  
        {  
            if(tempn[i]==1)  
                printf("%c",n[i]);  
        }  
        printf("\n");  
    }  
}          