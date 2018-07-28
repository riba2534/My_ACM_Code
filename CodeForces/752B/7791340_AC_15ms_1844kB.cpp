#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s1[1010],s2[1010],f[500];
int main()
{
    int i,j,k,l,p,q,x,y,z,ans;
    scanf("%s%s",s1+1,s2+1);
    l=strlen(s1+1);
    for (i=1; i<=l; i++)
        if (f[s1[i]]*f[s2[i]]==0)
        {
            if (f[s1[i]]+f[s2[i]]==0)
            {
                f[s1[i]]=s2[i];
                f[s2[i]]=s1[i];
            }
            else
            {
                printf("-1\n");
                return 0;
            }
        }
        else
        {
            if (f[s1[i]]!=s2[i]||f[s2[i]]!=s1[i])
            {
                printf("-1\n");
                return 0;
            }
        }
    ans=0;
    for (i='a'; i<='z'; i++)
        if (f[i]&&f[i]>i) ans++;
    printf("%d\n",ans);
    for (i='a'; i<='z'; i++)
        if (f[i]&&f[i]>i) printf("%c %c\n",i,f[i]);
}