#include<cstdio>
int a[100005];
int main()
{
    int n,i,c,ans,p;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    ans=1;
    c=1;
    for(i=1; i<n; i++)
    {
        if(a[i]>a[i-1])
        {
            c++;
        }
        else
        {
            if(c>ans)
            {
                ans=c;
            }
            c=1;
        }
    }
    if(c>ans)
    {
        ans=c;
    }
    printf("%d\n",ans);
    }


    return 0;
}
