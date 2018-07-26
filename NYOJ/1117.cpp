 
#include <stdio.h>  
#include <string.h>  
#include <queue>  
using namespace std;  
int main()  
{  
    deque<int>s;  
    char str[5];  
    int t,n;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d",&n);  
        for(int i=0;i<n;i++)  
        {  
            memset(str,0,sizeof(str));  
            scanf("%s",str);  
            if(strcmp(str,"push")==0)  
            {  
                int x;  
                scanf("%d",&x);  
                s.push_back(x);  
            }  
            else  
            s.pop_front();  
        }  
        if(!s.empty())  
        {  
            printf("%d",s.front());  
            s.pop_front();  
            while(!s.empty())  
            printf(" %d",s.front()),s.pop_front();  
            printf("\n");  
        }  
        else  
        printf("no eggs!\n");  
    }  
    return 0;  
}          