#include<stdio.h>
#include<string.h>
#include <algorithm>
using namespace std;
char s[1200];
int judge(char c)
{
    if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='Y')
        return 1;
    return 0;
}
int main()
{
    while(~scanf("%s",s+1))
    {
        int len=strlen(s+1);
        s[0]=s[len+1]='A';
        int maxx=0,sum=0;
        for(int i=0; i<=len+1; i++)
        {
            sum++;
            if(judge(s[i]))
            {
                maxx=max(maxx,sum);
                sum=0;
            }
        }
        printf("%d\n",maxx);
    }
    return 0;
}
