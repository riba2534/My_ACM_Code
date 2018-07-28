#include<algorithm>  
#include<math.h>  
#include <stdio.h>  
#include <cstring>  
using namespace std;  
int main()  
{  
    char ch[110];  
    while(scanf("%s",ch)!=EOF)  
    {  
        int ans=0;  
        ans=min(abs(ch[0]-'a'),abs(26-(ch[0]-'a')));  
        for(int i=1; i<strlen(ch); i++)  
        {  
            ans+=min(abs(ch[i]-ch[i-1]),26-abs(ch[i]-ch[i-1]));  
        }  
        printf("%d\n",ans);  
    }  
    return 0;  
}  