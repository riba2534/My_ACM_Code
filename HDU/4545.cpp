#include<stdio.h>
#include<string.h>
#define N 1005
int main()
{
    char s1[N],s2[N];
    int vis[27][27];
    int i,j;
    int flag;
    int t;
    char x,y;
    scanf("%d",&t);
    int sum=1;
    while(t--)
    {
        getchar();
        gets(s1);
        gets(s2);
        int n;
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        while(n--)
        {
            getchar();
            scanf("%c %c",&x,&y);
            vis[x-'a'+1][y-'a'+1]=1;
        }
        int len1,len2;
        len1=strlen(s1);
        len2=strlen(s2);
        i=0;
        j=0;
        flag=0;
        for(i=0; i<len1; i++)
        {
            if(j==len2)
                break;
            if(s1[i]==s2[j])
            {
                j++;
                continue;
            }
            while(s2[j]!=s1[i])
            {
                if(j==len2)
                {
                    flag=1;
                    break;
                }
                if(vis[s2[j]-'a'+1][s1[i]-'a'+1]==1)
                {
                    j++;
                    break;
                }
                else
                    j++;
            }
        }
        if(flag==0)
            printf("Case #%d: happy\n",sum++);
        else
            printf("Case #%d: unhappy\n",sum++);
    }
    return 0;
}