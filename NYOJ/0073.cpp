 
#include <stdio.h>
#include <string.h>
char a[1000],b[1000];
int main()
{
    while(1)
    {
        scanf("%s%s",a,b);
        int lena=strlen(a),lenb=strlen(b);
        if(a[0]=='0'&&b[0]=='0')
            break;
        if(a[0]=='-'&&b[0]=='-')//全是负数
        {
            if(lena>lenb)
            {
                printf("a<b\n");
            }
            else if(lena==lenb)
            {
                int i=1;
                for(i=1; i<lena; i++)
                {
                    if(a[i]!=b[i])
                        break;
                }
                if(a[i]>b[i])
                    printf("a<b\n");
                else if(a[i]<b[i])
                    printf("a>b\n");
                else if(a[i]==b[i])
                    printf("a==b\n");
            }
            else if(lena<lenb)
            {
                printf("a>b\n");
            }
        }
        else if(a[0]=='-'&&b[0]!='-')//a负,b正
        {
            printf("a<b\n");
        }
        else if(a[0]!='-'&&b[0]=='-')//a正，b负
        {
            printf("a>b\n");
        }
        else if(a[0]>='0'&&a[0]<='9')//全是正数
        {
            if(lena>lenb)
            {
                printf("a>b\n");
            }
            else if(lena==lenb)
            {
                int i=0;
                for(i=0; i<lena; i++)
                {
                    if(a[i]!=b[i])
                        break;
                }
                if(a[i]>b[i])
                    printf("a>b\n");
                else if(a[i]<b[i])
                    printf("a<b\n");
                else if(a[i]==b[i])
                    printf("a==b\n");
            }
            else if(lena<lenb)
            {
                printf("a<b\n");
            }
        }
    }
}
        