 
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

int a[210];
int main(){
    int T; 
	scanf("%d",&T);
    while(T--){
        memset(a,0,sizeof(a));
        int n;
        int sum=0; 
		int k=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(x<0)//<=就WA了
                sum-=x;
            else
                a[++k]=x;

        }
        sort(a+1,a+k+1);
        int ans=0;
        for (int i=1,j=k-1;i<j; i++,j--) {
            ans=abs(ans-a[j]);
            ans=abs(ans-a[i]);
        }
        if(!(k&1)){
            ans=abs(ans-a[k/2]);
        }
        sum+=abs(a[k]-ans);
        printf("%d\n",sum);
	}
	//system("pause");
    return 0;
}
                