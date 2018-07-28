#include <iostream>  
#include <cstdio>  
#include <vector>  
#include <cstring>  
#include <queue>  
using namespace std;  
typedef long long LL;  
const int N = 15;  
int dx[5] = {0,0,1,-1};  
int dy[5] = {1,-1,0,0};  
struct Node  
{  
    int x,y;  
    int cnt ;  
};  
vector<Node> v;  
char mp[N][N];  
int vis[N][N];  
int n,m;  
int BFS(Node a,Node b)  
{  
    memset(vis,0,sizeof(vis));  
    queue<Node> q;  
    vis[a.x][a.y]  = vis[b.x][b.y] = 1;  
    a.cnt = 0,b.cnt = 0;  
    q.push(a),q.push(b);  
    int ans = 0x3f3f3f3f;  
    int cas = 1;  
    while(!q.empty())  
    {  
        a = q.front();  
        q.pop();  
        //printf("%d %d %d\n",a.x,a.y,a.cnt);  
        ans = a.cnt;  
        for(int i = 0;i<4;i++)  
        {  
            b.x = a.x + dx[i];  
            b.y = a.y + dy[i];  
            b.cnt = a.cnt + 1;  
            //printf("B:%d %d %d\n",b.x,b.y,b.cnt);  
            if(b.x>0 && b.y>0 && b.x<=n && b.y<=m && vis[b.x][b.y]==0 && mp[b.x][b.y]=='#')  
            {  
                vis[b.x][b.y] = 1;  
                q.push(b);  
            }  
        }  
    }  
    return ans;  
}  
int main()  
{  
    //freopen("Input.txt","r",stdin);  
    int T;  
    scanf("%d",&T);  
    for(int cas=1;cas<=T;cas++)  
    {  
        v.clear();  
        scanf("%d%d",&n,&m);  
        for(int i=1;i<=n;i++)  
        {  
            getchar();  
            for(int j=1;j<=m;j++){  
                scanf("%c",&mp[i][j]);  
                if(mp[i][j]=='#')  
                    v.push_back((Node){i,j,0});  
            }  
        }  
        int ans = 0x3f3f3f3f;  
        for(int i=0;i<v.size();i++)  
        {  
            for(int j=i;j<v.size();j++)  
            {  
                int tmp = BFS(v[i],v[j]);  
                bool ok = true;  
                for(int k = 1;k<=n;k++)  
                {  
                    for(int f = 1;f<=m;f++)  
                    {  
                        if(vis[k][f] == 0 && mp[k][f]=='#')  
                        {  
                            ok = false;  
                            break;  
                        }  
                    }  
                    if(ok==false)  
                        break;  
                }  
                if(ok)  
                {  
                    ans = min(ans,tmp);  
                }  
            }  
        }  
        printf("Case %d: ",cas);  
        if(ans == 0x3f3f3f3f)  
            puts("-1");  
        else  
            printf("%d\n",ans);  
    }  
    return 0;  
}  