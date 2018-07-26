 
#include <stdio.h>
#include <math.h>
int main()
{
    char a1,a2,a3,a4,b1,b2,b3,b4;
    char c[5],d[5];

    while(scanf("%c %c %c %c %c %c %c %c",&a1,&a2,&a3,&a4,&b1,&b2,&b3,&b4)!=EOF)
    { getchar();
        int ax=0,ay=0,bx=0,by=0;
       // printf("%d %d %d %d\n",ax,ay,bx,by);
        c[1]=a1;
        c[2]=a2;
        c[3]=a3;
        c[4]=a4;
        d[1]=b1;
        d[2]=b2;
        d[3]=b3;
        d[4]=b4;
       // printf("-------%c %c %c %c %c %c %c %c\n",c[1],c[2],c[3],c[4],d[1],d[2],d[3],d[4]);
        for(int i=1; i<=4; i++)
        {
            if(c[i]=='W')
                ax-=1;
            else if(c[i]=='E')
                ax+=1;
            else if(c[i]=='N')
                ay+=1;
            else if(c[i]=='S')
                ay-=1;
        }
        for(int i=1; i<=4; i++)
        {
            if(d[i]=='W')
                bx-=1;
            else if(d[i]=='E')
                bx+=1;
            else if(d[i]=='N')
                by+=1;
            else if(d[i]=='S')
                by-=1;
        }
       // printf("%d %d %d %d\n",ax,ay,bx,by);
        double a,b;
        a=(ax-bx)*(ax-bx)+(ay-by)*(ay-by);
        b=sqrt(a);
        printf("%.2f\n",b);
    }


    return 0;
}        