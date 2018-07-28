#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<deque>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<functional>
using namespace std;

#define N 256+10
char s[N];
struct Node
{
    int v;
    bool have_value;
    Node*left, *right;
    Node() :have_value(false), left(NULL), right(NULL) {}
};
Node*root;//根结点，使用前要申请空间
bool failed;//记录输入是否有误
Node*newnode()
{
    return new Node();
}
void addnode(int v, char*s)
{
    int n = strlen(s);
    Node*u = root;
    for (int i = 0; i < n; i++)
        if (s[i] == 'L')
        {
            if (u->left == NULL)u->left = newnode();
            u = u->left;
        }
        else if (s[i] == 'R')
        {
            if (u->right == NULL)u->right = newnode();
            u = u->right;
        }
    if (u->have_value)failed = true;//已经赋过值了，说明输入有误
    u->v = v;
    u->have_value = true;//标记为已经赋值
}
bool readin()//读数据
{
    failed = false;
    for (;;)
    {
        if (scanf("%s", s)!=1)return false;//整个输入结束
        if (!strcmp(s, "()"))break;//读到结束标志，退出循环
        int v;
        sscanf(&s[1], "%d", &v);//读入结点值
        addnode(v, strchr(s, ',') + 1);//查找逗号，然后插入结点
    }
    return true;
}
bool bfs(vector<int>&ans)//利用bfs进行遍历，并将结点值放入vector中
{
    queue<Node*>q;
    ans.clear();
    q.push(root);
    while (!q.empty())
    {
        Node*u = q.front();
        q.pop();
        if (!u->have_value)return false;//没有结点值，返回false
        ans.push_back(u->v);
        if (u->left != NULL)q.push(u->left);
        if (u->right != NULL)q.push(u->right);
    }
    return true;
}
int main()
{
    //freopen("t.txt", "r", stdin);
    while(1)
    {
        root = newnode();
        if (!readin())break;
        vector<int>ans;
        if (!failed&&bfs(ans))
        {
            int len = ans.size();
            for (int i = 0; i < len; i++)
                printf("%d%c", ans[i], i == len - 1 ? '\n' : ' ');
        }
        else puts("not complete");
    }
    return 0;
}
