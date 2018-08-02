# A. Points in Segments

题目链接：[Points in Segments](http://codeforces.com/contest/1015/problem/A)

分类：暴力

题意：给出你一些区间，然后覆盖了一些，问哪些没有被覆盖

思路：直接标记一下做就行了

代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int N=1e6+10;
int vis[N];
int main()
{
    int n,m,l,r;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&l,&r);
        for(int j=l; j<=r; j++)vis[j]=1;
    }
    vector<int>v;
    for(int i=1; i<=m; i++)
        if(!vis[i])
            v.push_back(i);
    printf("%d\n",v.size());
    for(auto num:v)
    {
        printf("%d ",num);
    }
    puts("");
    return 0;
}

```

# B. Obtaining the String

题目链接:[Obtaining the String](http://codeforces.com/contest/1015/problem/B) 

分类：暴力

题意：给你两个串，求每次只交换相邻的两个字符，如何才能把第一个串变成第二个串，但是移动次数不能超过$10^4$

思路：直接$O(N)$扫一遍，当遇见不同的字符的时候,就倒着交换，知道两个串一致为止

代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
string s1, s2;
int main()
{
    vector<int> v;
    int n;
    cin >> n >> s1 >> s2;
    for (int i = 0; i < n; i++)
    {
        int pos = s1.find(s2[i], i);
        if (pos == -1)
        {
            cout << -1 << endl;
            return 0;
        }
        while (pos > i)
        {
            swap(s1[pos - 1], s1[pos]);
            v.push_back(pos--);
        }
    }
    cout << v.size() << endl;
    for (auto num : v)
        cout << num << " ";
    cout << endl;

    return 0;
}
```



# C. Songs Compression

题目链接：[Songs Compression](http://codeforces.com/contest/1015/problem/C) 

分类：贪心

题意：一个人手机里面有$n$首歌曲，每首歌曲所占用的存储空间是$a_i$,他还有一个u盘，存储空间是$m$,现在他需要把手机里面的歌曲拷贝一份在u盘上面，但是u盘的容量不一定够，所以他需要压缩一些歌曲，对于每一首歌曲我们知道压缩后这个歌曲会变成多大,现在求最少压缩几首歌曲使得u盘可以存储下所有的歌曲，如果无论如何也存不输出`-1`.

思路：首先计算所有歌曲都没有被压缩所占用的空间，如果可以存下就输出`0`，再计算出所有歌曲都被压缩总共占用的空间，如果u盘还是存不下就输出`-1`。对这两种情况进行特判以后，按照压缩前后的差值从大到小排序，然后逐个压缩，知道u盘可以存下为止

代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10;
struct node
{
    ll st,ed,cha;
} a[N];
bool cmp(node A,node B)
{
    return A.cha>B.cha;
}
int main()
{
    ll n,m,sum1=0,sum2=0;
    scanf("%lld%lld",&n,&m);
    for(ll i=1; i<=n; i++)
    {
        scanf("%lld%lld",&a[i].st,&a[i].ed);
        sum1+=a[i].st;
        sum2+=a[i].ed;
        a[i].cha=a[i].st-a[i].ed;
    }
    if(sum1<=m)
    {
        puts("0");
        return 0;
    }
    if(sum2>m)
    {
        puts("-1");
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    ll ans=0;
    for(ll i=1; i<=n; i++)
    {
        if(sum1<=m)
        {
            printf("%lld\n",ans);
            return 0;
        }
        sum1-=a[i].cha;
        ans++;
    }
    printf("%lld\n",ans);
    return 0;
}

```



# D. Walking Between Houses

题目链接：[Walking Between Houses](http://codeforces.com/contest/1015/problem/D) 

分类：构造

题意：给一个$n,k,s$代表现在有$n$个房子，你需要搬家$k$次，搬家的总的距离为$s$。每次搬家的距离定义为$|x-y|$(x,y为第几个房子),让你构造一个转移序列，满足正好为$k$次，总距离为$s$.

首先我们判断:

1. $s<k$时一定构造不出来
2. $k*(n-1)<s$时也构造不出来

对于其他情况，一定可以构造，我们每次转移的距离选择`s-k`和`n-1`中比较小的那一个，然后总距离减去走的距离，当当前走的距离加上转移的距离大于`n`的时候，就要往回走，然后一直走下去，就可以构造出来序列了。

代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10;
int main()
{
    ll n, k, s;
    scanf("%lld%lld%lld", &n, &k, &s);
    if (s < k || k * (n - 1) < s)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    ll st = 1;
    while (k--)
    {
        ll dis = min(s - k, n - 1);
        s -= dis;
        if (st + dis <= n)
            st += dis;
        else
            st -= dis;
        printf("%lld ", st);
    }
    puts("");
    return 0;
}
```



# E1. Stars Drawing (Easy Edition) 

题目链接:[Stars Drawing (Easy Edition)](http://codeforces.com/problemset/problem/1015/E1)

分类：思路，模拟

题意：给了一个$n*m$的格子，问你当用完所有的星星的时候，格子里面最多有几个星星(星星的定义看题目给的图就知道了)，让你输出星星的数量，然后输出$x_i,y_i,s_i$分别表示横纵坐标和星星的大小，当不能用完所有的星星时输出$-1$.

思路：$O(n^2)$遍历整个图，对于每一个符号为`*`的地方，判断当前位置最大有几个星星(一直往上下左右找,注意判断越界)，如果有星星的话，就加入答案，没有星星就跳过,用一个数组标记每一个`*`有没有被用过，当星星数完之后如果还有`*`没有被标记，就输出`-1`,否则输出我们存储的答案，复杂度为$O(n^2)$

代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N=1000+20;
char s[N][N];
int vis[N][N];
int n,m;
struct pos
{
    int x,y,s;
    pos(int _x,int _y,int _s)
    {
        x=_x,y=_y,s=_s;
    }
};
vector<pos>v;
int pd(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m&&s[x][y]=='*')
        return 1;
    return 0;
}
int get_len(int x,int y)
{
    int len=0;
    for(int i=1;; i++)
    {
        if(pd(x-i,y)&&pd(x+i,y)&&pd(x,y-i)&&pd(x,y+i))
        {
            vis[x][y]=1;
            len=i;
            vis[x-i][y]=vis[x+i][y]=vis[x][y-i]=vis[x][y+i]=1;
        }
        else
            break;
    }
    return len;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%s",s[i]);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(s[i][j]=='*')
            {
                int len=get_len(i,j);
                if(len>0)
                    v.push_back(pos(i,j,len));
            }
    int flag=1;
    for(int i=0; i<n&&flag; i++)
        for(int j=0; j<m&&flag; j++)
            if(s[i][j]=='*'&&!vis[i][j])
                flag=0;
    if(flag)
    {
        printf("%d\n",v.size());
        for(pos ans:v)
            printf("%d %d %d\n",ans.x+1,ans.y+1,ans.s);
    }
    else
        puts("-1");
    return 0;
}
/*
5 5
.*...
****.
.****
..**.
.....
*/

```





# E2. Stars Drawing (Hard Edition)

题目链接：[Stars Drawing (Hard Edition)](http://codeforces.com/contest/1015/problem/E2) 

题面和上一题一模一样，仅仅把图的规模从100变成了1000，因为当时的复杂度是$O(n^2)$，所以改一下数组大小也可以过这个题

代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N=1000+20;
char s[N][N];
int vis[N][N];
int n,m;
struct pos
{
    int x,y,s;
    pos(int _x,int _y,int _s)
    {
        x=_x,y=_y,s=_s;
    }
};
vector<pos>v;
int pd(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m&&s[x][y]=='*')
        return 1;
    return 0;
}
int get_len(int x,int y)
{
    int len=0;
    for(int i=1;; i++)
    {
        if(pd(x-i,y)&&pd(x+i,y)&&pd(x,y-i)&&pd(x,y+i))
        {
            vis[x][y]=1;
            len=i;
            vis[x-i][y]=vis[x+i][y]=vis[x][y-i]=vis[x][y+i]=1;
        }
        else
            break;
    }
    return len;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%s",s[i]);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(s[i][j]=='*')
            {
                int len=get_len(i,j);
                if(len>0)
                    v.push_back(pos(i,j,len));
            }
    int flag=1;
    for(int i=0; i<n&&flag; i++)
        for(int j=0; j<m&&flag; j++)
            if(s[i][j]=='*'&&!vis[i][j])
                flag=0;
    if(flag)
    {
        printf("%d\n",v.size());
        for(pos ans:v)
            printf("%d %d %d\n",ans.x+1,ans.y+1,ans.s);
    }
    else
        puts("-1");
    return 0;
}
/*
5 5
.*...
****.
.****
..**.
.....
*/

```
