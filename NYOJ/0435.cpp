 
#include <cstdio>  
#include <cstring>  
#define MAXN 10  
typedef long long LL;  
struct NDOE{//保存枚举的任意两行之间合法的状态  
    int now, last;  
}p[79500];  
int h,w,len;  
LL dp[MAXN+1][1<<9];  
//dp[i][s]表示前i-1行全部填满第i行状态为s时有多少种方案  
  
//dfs()生成出:i行和i-1行还没被填满，1~i-2行已经被填满时的i行和i-1行的状态使得1~i行都被填满  
//b1:i行当前这一列有没有被占，b2:i-1行当前这一列有没有被占  
void dfs(int j, int now, int last, int b1, int b2)  
{  
    if (j == w)  
    {  
        if (!b1 && !b2)  
            p[len].now = now, p[len++].last = last;  
        return;  
    }  
    dfs(j+1,now<<1|b1,last<<1|1^b2,0,0);/*不放;i行可以不被填满(因为可以被i+1行填满)->now继承状态b1 
    但是i-1行必须要被填满了,所以last填上1，但如果b2=1说明当前i-1行已经可以被前面填满,则这个last状态 
    填上0，可以想像成还空这个位置去填补它，而这里枚举的是填补以前的，所以也就是中间会空出来。 
    也就是有两种填入方式:一种是本来就填好了前面状态已经记录过，还有一种则需要现在去填,结果都要使得全部填满 
    可以想象成你现在在生成一个地形，中间有些还没被填满的空格都是1*2和L型的，最终可以用这两种填满它*/  
    /*一句话，当前该位置如果已经填了就不能再填，如果没填就可以填*/  
    if (!b1)  
    {  
        dfs(j+1,now<<1|1,last<<1|1^b2,1,0);//1*2横放  
        dfs(j+1,now<<1|1,last<<1|1^b2,1,1);//缺左上角  
        if(!b2)  
        {  
            dfs(j+1,now<<1|1,last<<1,0,0);//1*2竖放  
            dfs(j+1,now<<1|1,last<<1,1,0);//缺右上角  
            dfs(j+1,now<<1|1,last<<1,0,1);//缺右下角  
        }  
    }  
    if (!b2)  
        dfs(j+1,now<<1|b1,last<<1,1,1);//缺左下角  
}  
int main()  
{  
#ifdef SHY  
    freopen("e:\\1.txt","r",stdin);  
#endif  
    while(~scanf("%d %d%*c", &h, &w))  
    {  
        if (h < w)  
        {  
            h ^= w;  
            w ^= h;  
            h ^= w;  
        }  
        len = 0;  
        dfs(0,0,0,0,0);  
        memset(dp,0,sizeof(dp));  
        dp[0][(1<<w)-1] = 1;  
        for (int i = 1; i <= h; i++)  
        {  
            for (int j = 0; j < len; j++)  
                dp[i][p[j].now] += dp[i-1][p[j].last];  
        }  
        printf("%lld\n", dp[h][(1<<w)-1]);  
    }  
    return 0;  
}          