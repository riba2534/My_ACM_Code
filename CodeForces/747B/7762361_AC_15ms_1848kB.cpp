#include <stdio.h>  
#include <string.h>  
#include <stack>  
#include <cmath>  
#include <queue>  
#include <algorithm>  
#define mem(a,b) memset(a,b,sizeof(a))  
using namespace std;  
char str[1000];  
int main()  
{  
    int n;  
    while(~scanf("%d",&n))  
    {  
        scanf("%s",str);  
        if(n%4!=0)  
            printf("===\n");  
        else  
        {  
            int len=strlen(str);  
            int a=0,g=0,c=0,t=0,q=0;  
            for(int i=0; i<len; i++)  
            {  
                if(str[i]=='A')a++;  
                if(str[i]=='G')g++;  
                if(str[i]=='T')t++;  
                if(str[i]=='C')c++;  
                if(str[i]=='?')q++;  
            }  
            int num=n/4;  
            int a1=num-a,g1=num-g,c1=num-c,t1=num-t;  
            if(q==0&&a<=num&&c<=num&&g<=num&&t<=num&&a>0&&c>0&&g>0&&t>0)  
            {  
                printf("%s\n",str);  
                continue;  
            }  
            if(a>num||g>num||t>num||c>num)  
                printf("===\n");  
            else  
            {  
                for(int i=0; i<len; i++)  
                {  
                    if(str[i]!='?')  
                        printf("%c",str[i]);  
                    else  
                    {  
                        if(a1>0)  
                        {  
                            printf("A");  
                            a1--;  
                            continue;  
                        }  
                        if(c1>0)  
                        {  
                            printf("C");  
                            c1--;  
                            continue;  
                        }  
                        if(g1>0)  
                        {  
                            printf("G");  
                            g1--;  
                            continue;  
                        }  
  
                        if(t1>0)  
                        {  
                            printf("T");  
                            t1--;  
                            continue;  
                        }  
                    }  
                }  
                printf("\n");  
            }  
        }  
    }  
    return 0;  
} 