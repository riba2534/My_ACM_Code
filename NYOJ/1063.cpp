 
//#include <bits/stdc++.h>
//using namespace std;
//struct tnode						/*定义二叉树存储结构*/
//{
//    char data;
//    struct tnode*lchild;
//    struct tnode*rchild;
//};
//struct tnode tree;						/*定义二叉树指针*/
//
//void createtree(struct tnode*t)				/*创建函数*/
//{
//    struct tnode*p=t;						/*把二叉树指针给p*/
//    char check;
//    if(p->lchild==NULL||p->rchild==NULL)	 /*判断左右子树是否为空*/
//    {
//        printf("please enter the data:");			  /*输入根结点数据*/
//        scanf("%c",&(p->data));
//        getchar();
//    }
//    if(p->lchild==NULL)
//    {
//        printf("%c  leftchild is null.Add? y/n\n",p->data); /*左子树空，询问是否创建*/
//        scanf("%c",&check);
//        getchar();
//        if(check=='y')
//        {
//            struct tnode*q=(struct tnode*)malloc(sizeof(struct tnode)); /*开辟空间*/
//            q->lchild=NULL;
//            q->rchild=NULL;
//            p->lchild=q;
//            createtree(q);
//        }
//    }
//    if(p->rchild==NULL)
//    {
//        printf("%c rightchild is NULL.Add? y/n\n",p->data); /*右子树空，询问是否创建*/
//        scanf("%c",&check);
//        getchar();
//        if(check=='y')
//        {
//            struct tnode*q=(struct tnode*)malloc(sizeof(struct tnode)); /*开辟空间*/
//            q->lchild=NULL;
//            q->rchild=NULL;
//            p->rchild=q; 							/*连到二叉树上*/
//            createtree(q);
//        }
//    }
//}
//
//void preorder(struct tnode*t)				/*先序遍历函数*/
//{
//    if(t)
//    {
//        printf("%c ",t->data);				/*输出根结点数据*/
//        preorder(t->lchild);
//        preorder(t->rchild);
//    }
//}
//
//void inorder(struct tnode*t)				 /*中序遍历函数*/
//{
//    if(t)
//    {
//        inorder(t->lchild);
//        printf("%c ",t->data);
//        inorder(t->rchild);
//    }
//}
//void postorder(struct tnode*t) /*后序遍历函数*/
//{
//    if(t)
//    {
//        postorder(t->lchild);
//        postorder(t->rchild);
//        printf("%c ",t->data);
//    }
//}
//
//int main()
//{
////    clrscr();							/*清屏函数*/
//    tree.lchild=NULL;					/*左子树*/
//    tree.rchild=NULL;					/*右子树*/
//    createtree(&tree); 					/*创建二叉树*/
//    preorder(&tree);					/*先序遍历*/
//    printf("\n");
//    inorder(&tree);					/*中序遍历*/
//    printf("\n");
//    postorder(&tree);					/*后序遍历*/
//}
//
//
//
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
struct Bitree
{
    string data;
    Bitree *lchild,*rchild;
};


void build(Bitree * &r)//建树
{
    string temp;
    cin>>temp;
    if(temp=="#")
        r=NULL;
    else
    {
        r=new Bitree;
        r->data=temp;
        build(r->lchild);
        build(r->rchild);
    }
}

queue<string>ans;
void solve(Bitree *r,int step,int deep)
{
    if(r==NULL)
        return;
    if(step==deep)
    {
        ans.push(r->data);
        return;
    }
    solve(r->lchild,step+1,deep);
    solve(r->rchild,step+1,deep);
}
//void dfs(Bitree *t)
//{
//    if(t==NULL) return ;
//    cout<<t->data<<endl;
//    dfs(t->lchild);
//    dfs(t->rchild);
//}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string c;
        int n;
        Bitree *T=NULL;
        build(T);
        //dfs(T);
       // return 0;
        cin>>c>>n;
        solve(T,1,n);
        //puts("sdsds");
        int len=ans.size();
        if(len>1)
        {
            for(int i=0; i<len-1; i++)
            {
                cout<<ans.front()<<"~";
                ans.pop();
            }
        }
        cout<<ans.front()<<endl;
        ans.pop();
    }
    return 0;
}
        