#include <string.h>
#include <stdio.h>
#include <ctype.h>

int a[200];
int e;

void find1(char s[], char t[])
{
    int i, j;
    int len, ll;
    len=strlen(s)-strlen(t);
    ll=strlen(t);
    e=0;
    memset(a, -1, sizeof(-1));
    for(i=0; i<=len; i++)
    {
        if(s[i]==t[0])
        {
            for(j=1; j<ll; j++)
            {
                if(s[i+j]!=t[j] )
                {
                    break;
                }
            }
            if(j==ll)
            {
                a[e++]=i;
            }
            j=0;
        }
    }
}


int main()
{
    char s1[300];
    char s2[300];
    char t[10]="marshtomp";
    int i, j;
    int len;

    while(gets(s1)!=NULL )
    {
        len=strlen(s1);

        for(i=0; i<len; i++)
        {
            s2[i]=tolower(s1[i]);
        }
        find1(s2, t);
        int k=0;
        for(i=0; i<len; )
        {
            if(i==a[k])
            {
                printf("fjxmlhx");
                i+=9;
                k++;
            }
            else
            {
                printf("%c", s1[i]);
                i++;
            }
        }
        printf("\n");
    }
    return 0;
}
