 
#include<stdio.h>
main()
{
char str[40];
int n, i;
scanf("%d",&n);
getchar();
while(n--){
gets(str);
for(i = 0; str[i] != '\0'; i++)
;
i = i - 1;
for(; i >= 0; i--){
if(str[i] >= 'a' && str[i] <= 'z')
printf("%c",str[i]);
}
printf("\n");
}
return 0;
}        