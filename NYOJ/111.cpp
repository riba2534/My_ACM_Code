 
# include <stdio.h>
int main()
{
    int yuefen(int *a, int *b);
    int gcd(int x,int y);
    int a, b, c, d, y;
    int *p1, *p2;
    char o;
    while (scanf("%d/%d%c%d/%d", &a, &b, &o, &c, &d)!=EOF)
    {
        if (b>d)
            y=gcd(b, d);
        else
            y=gcd(d, b);
        a=a*(d/y);
        c=c*(b/y);
        b=d/y*b;
        d=b;
        if (o=='+')
            a=a+c;
        else if(o=='-')
            a=a-c;
        else
        {
            printf("error!\n");
            continue;
        }
        if (0 == a%b)
        {
            printf("%d\n", a/b);
        }
        else if (a>0)
        {
            p1=&a;
            p2=&b;
            yuefen(p1, p2);
            printf("%d/%d\n", a, b);
        }
        else
        {
            a=-a;
            p1=&a;
            p2=&b;
            yuefen(p1, p2);
            printf("%d/%d\n", -a, b);
        }
    }
    return 0;
}

int yuefen(int *a, int *b)	//约分
{
    int gcd(int x,int y);
    int ys;
    ys = gcd(*a,*b);
    *a=*a/ ys;
    *b=*b/ ys;
    return 0;
}

int gcd(int x,int y)	// 2个数的公约数
{
    int t, a, b;
    a=x;
    b=y;
    while(b)
    {
        t = (a) % (b);
        a = b;
        b = t;
    }
    return a;
}
        