 
#include<stdio.h>  
int main()  
{  
    int n,i,j,k=0;  
    scanf("%d",&n);  
    while(n--)  
    {  
        char s[200]="\0";  
        scanf("%s",s);  
        for(i=0,j=0;i<200;i++)  
        {  
            if(s[i]>='a'&&s[i]<='z')  
                j++;  
        }  
        switch(j%26){  
        case 0:printf("z\n");break;  
        case 1:printf("a\n");break;  
        case 2:printf("b\n");break;  
        case 3:printf("c\n");break;  
        case 4:printf("d\n");break;  
        case 5:printf("e\n");break;  
        case 6:printf("f\n");break;  
        case 7:printf("g\n");break;  
        case 8:printf("h\n");break;  
        case 9:printf("i\n");break;  
        case 10:printf("j\n");break;  
        case 11:printf("k\n");break;  
        case 12:printf("l\n");break;  
        case 13:printf("m\n");break;  
        case 14:printf("n\n");break;  
        case 15:printf("o\n");break;  
        case 16:printf("p\n");break;  
        case 17:printf("q\n");break;  
        case 18:printf("r\n");break;  
        case 19:printf("s\n");break;  
        case 20:printf("t\n");break;  
        case 21:printf("u\n");break;  
        case 22:printf("v\n");break;  
        case 23:printf("w\n");break;  
        case 24:printf("x\n");break;  
        case 25:printf("y\n");break;  
        default:break;  
        }  
    }  
    return 0;  
}  
        