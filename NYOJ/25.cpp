 
#include <stdio.h>
#include <string.h>
int main()
{
    char s1[10],s2[10];
    int sign = 1;
    while(scanf("%s%s",s1,s2) != EOF)
    {
        printf("Case %d: ",sign++);
        if(!strcmp(s1,"A#")) printf("%s %s\n","Bb",s2);
        else if(!strcmp(s1,"Bb")) printf("%s %s\n","A#",s2);
        else if(!strcmp(s1,"C#")) printf("%s %s\n","Db",s2);
        else if(!strcmp(s1,"Db")) printf("%s %s\n","C#",s2);
        else if(!strcmp(s1,"D#")) printf("%s %s\n","Eb",s2);
        else if(!strcmp(s1,"Eb")) printf("%s %s\n","D#",s2);
        else if(!strcmp(s1,"F#")) printf("%s %s\n","Gb",s2);
        else if(!strcmp(s1,"Gb")) printf("%s %s\n","F#",s2);
        else if(!strcmp(s1,"G#")) printf("%s %s\n","Ab",s2);
        else if(!strcmp(s1,"Ab")) printf("%s %s\n","G#",s2);
        else printf("UNIQUE\n");
    }
}
        