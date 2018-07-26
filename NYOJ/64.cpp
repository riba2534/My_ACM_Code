 
#include <stdio.h> 
int main() 
{ 
    
int q, i = 0; 
 
scanf("%d",&q); 
   
while (1) 
    
{ 
        
int a, b, n, m; 
        
scanf("%d%d",&n,&m); 
        
a = (4 * n - m) / 2; 
        
b = n - a; 
       
if (m % 2 == 1 || a < 0 || b < 0) 
            
printf("No answer\n"); 
       
else
           
printf("%d %d\n",a,b); 
       
i++; 
       
if (i >= q) 
            
break; 
   
} 
  
return 0; 
}        