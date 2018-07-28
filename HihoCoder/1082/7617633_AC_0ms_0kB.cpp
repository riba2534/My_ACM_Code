#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int main()
{
    char a[10000];
    int flag;
    while(gets(a))
    {
        for(int i=0; i<strlen(a); i++)
        {
            flag=0;
            if(a[i]=='m'||a[i]=='M') flag++;
            if(a[i+1]=='a'||a[i+1]=='A') flag++;
            if(a[i+2]=='r'||a[i+2]=='R') flag++;
            if(a[i+3]=='s'||a[i+3]=='S') flag++;
            if(a[i+4]=='h'||a[i+4]=='H') flag++;
            if(a[i+5]=='t'||a[i+5]=='T') flag++;
            if(a[i+6]=='o'||a[i+6]=='O') flag++;
            if(a[i+7]=='m'||a[i+7]=='M') flag++;
            if(a[i+8]=='p'||a[i+8]=='P') flag++;
            if(flag==9)
                printf("fjxmlhx"),i+=8;
            else
                printf("%c",a[i]);
        }
        printf("\n");
    }
    return 0;
}


