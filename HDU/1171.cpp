#include <iostream>  
#include <cstring>  
using namespace std;  
#define MAX 250010  
int n,a[MAX],b[MAX],i,j,k,last,last2,v[50],m[50];  
int main()  
{  
    while ((cin>>n)&&n>=0)  
    {  
        for (i=0;i<n;i++)  
            cin>>v[i]>>m[i];  
        a[0]=1;  
        last=0;  
        for (i=0;i<n;i++)  
        {  
            last2=last+m[i]*v[i];  
            memset(b,0,sizeof(int)*(last2+1));  
            for (j=0;j<=m[i];j++)  
                for (k=0;k<=last;k++)  
                    b[k+j*v[i]]+=a[k];  
            memcpy(a,b,sizeof(int)*(last2+1));  
            last=last2;  
        }  
        for (i=last/2;i>=0&&a[i]==0;i--);  
        cout<<last-i<<' '<<i<<endl;  
    }  
    return 0;  
}  