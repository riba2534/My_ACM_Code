 
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define debug() puts("what the fuck!!!")
#define ll long long
using namespace std;
const int N=1010;
struct node
{
    int num;
    struct node *next[26];
};
struct node *root;
node *build()
{
    struct node *p=(node*)malloc(sizeof(node));
    p->num=1;
    for(int i=0; i<26; i++)
        p->next[i]=NULL;
    return p;
}
int insert(char *s)
{
    struct node *p=root;
    int len=strlen(s);
    for(int i=0; i<len; i++)
    {
        if(p->next[s[i]-'a']==NULL)
            p->next[s[i]-'a']=build();
        p=p->next[s[i]-'a'];
    }
    return p->num++;
}
int main()
{
    int t;
    int max=-1;
    char str[10],s[10];
    root=build();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        int a=insert(str);
        if(a>max)
        {
            max=a;
            strcpy(s,str);
        }
    }
    printf("%s %d\n",s,max);
    return 0;
}        