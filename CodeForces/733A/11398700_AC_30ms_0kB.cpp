#include <stdio.h>  
#include <string.h>  
int main()  
{  
    char a[1001];  
    while(~scanf("%s",a+1))  
    {  
        a[0]='E';  
        int len=strlen(a),sum=1,q=0;  
        a[len]='E';  
        int i,j;  
        for(int k=1; k<len; k++)  
        {  
            if(a[k]=='A'||a[k]=='E'||a[k]=='I'||a[k]=='O'||a[k]=='U'||a[k]=='Y')  
                q++;  
        }  
        for(i=0; i<=len; i++)  
        {  
            if(a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U'||a[i]=='Y')  
            {  
                for(j=i; j<=len; j++)  
                {  
                    if(a[j]=='A'||a[j]=='E'||a[j]=='I'||a[j]=='O'||a[j]=='U'||a[j]=='Y')  
                    {  
                        if(j-i>sum)  
                            sum=j-i;  
                        i=j;  
                        continue;  
                    }  
                }  
            }  
        }  
        if(q!=0)  
            printf("%d\n",sum);  
        else  
        {  
            printf("%d\n",len);  
        }  
    }  
    return 0;  
}  