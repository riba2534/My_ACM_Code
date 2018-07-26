 
#include <stdio.h> 
int main() 
{ 
    
int a, score,i=0; 
     
 
  
scanf("%d", &a); 
   
while (1) 
  
{ 
       
scanf("%d",&score); 
       
i++; 
      
if (score >= 90 && score <= 100) 
          
printf("A\n"); 
      
if (score >= 80 && score <= 89) 
           
printf("B\n"); 
      
if (score >= 70 && score <= 79) 
           
printf("C\n"); 
      
if (score >= 60 && score <= 69) 
           
printf("D\n"); 
       
if (score >= 0 && score <= 59) 
            
printf("E\n"); 
       
if (i >= a) 
          
break; 
    
} 

 
    
return 0; 
}
        