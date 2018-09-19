#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string s;
        cin>>s;
        if(s.size()!=6)
        {
           printf("Dare you say that again?\n");
        }
        else
        {
            for(int i=0;i<s.size();i++)
            {
                if(s[i]>='A'&&s[i]<='Z')
                    s[i]=s[i]-'A'+'a';
            }
            if(s=="jessie")
            {
                printf("Good guy!\n");
            }
            else
                 printf("Dare you say that again?\n");
        }
    }
    return 0;
}
