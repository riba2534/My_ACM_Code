#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    char s[8],maxx;
    int len;
    while(~scanf("%s",s))
    {  //接下来找出其中最大值就行；
        len=strlen(s);
        maxx=s[0];
        for(int i=1;i<len;i++)
        {
            if(maxx<s[i])
              maxx=s[i];
        }
        printf("%c\n",maxx);
        memset(s,0,sizeof(s));
    }
}
