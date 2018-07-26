 
#include <stdio.h>
int main()
{

    char m[3];
    while(scanf("%s",m)!=EOF)
    {
        for(int i=2;i>=0;i--)
        {
            printf("%c",m[i]);
        }
//        for(int i=2;i<0;i--)
//        {
//            printf("%c",m[i]);
//        }
        printf("\n");
    }


    return 0;
}        