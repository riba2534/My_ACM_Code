#include<bits/stdc++.h>
using namespace std;
const int N=21000;
char str[N];
int m,len;
int solve()
{
    int ans=0;
    for(int i=len; i>=1; i--)
    {
        int cnt=i/2-1,d=0,t=0,p=0;
        for(int j=0; j<=cnt; j++)
        {
            d+=abs(str[1+j]-str[i-j]);
            if(d>m)
            {
                d-=abs(str[1+p]-str[i-p]);
                d-=abs(str[1+j]-str[i-j]);
                p++;
                t--;
                j--;
            }
            else
            {
                t++;
                ans=max(ans,t);
            }
        }
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int ans=0;
        scanf("%d%s",&m,str+1);
        len=strlen(str+1);
        ans=max(ans,solve());
        reverse(str+1,str+len+1);
        ans=max(ans,solve());
        printf("%d\n",ans);
    }
    return 0;
}