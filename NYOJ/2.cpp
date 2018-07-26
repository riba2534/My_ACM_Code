 
#include<stdio.h>
#include<string.h>
int peidui(char a,char b)//检测是否括号配对
{
    if (a==')'&&b=='(')
        return 1;
    if (a==']'&&b=='[')
        return 1;
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while (t--)
    {
        char s[10001]= {0},ch[10001]= {0};
        int top=0,len,num=0;
        gets(s);//写入字符串到数组
        len=strlen(s);
        if (len%2==1)
        {
            printf("No\n");//奇数不可能配对
        }
        else
        {
            for (int i=0; i<len; i++)
            {

                if (s[i]=='('||s[i]=='[')
                    ch[top++]=s[i];//当当前的值是左括号时，压栈进入top
                //printf("ch[%d]=%c,s[%d]=%c\n",top-1,ch[top-1],i,s[i]);
                if (s[i]==')'||s[i]==']')//检测当前的值是否和栈中的括号配对
                {
                    if (peidui(s[i],ch[top-1]))
                    {
                       // printf("第二s[%d]=%c,ch[%d]=%c\n",i,s[i],top-1,ch[top-1]);
                        top--;//如果两个括号符配对，出栈
                        num++;//表示已经配对一组括号
                    }
                }
            }
            if (num==len/2)//检测配对的括号是否是总长度的一半
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
        