 
#include<stdio.h>
int main()
{
    int T,max,i;
    char s[1011];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        int a[26]= {0};
        for(i=0; s[i]!='\0'; i++)
            a[s[i]-'a']++;
        max=0;
        for(i=1; i<26; i++)
            if(a[i]>a[max])
                max=i;
        printf("%c\n",max+'a');
    }
    return 0;
}        