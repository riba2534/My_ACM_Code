#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 1000007
#define N 20100
#define M 100000+50
#define ll long long
using namespace std;
int id[26];//记录顶点的入度
int temp[26];//count的复制，拓扑排序时进行修改
char str[3],seq[26];//seq用来记录最终的序列
int vis[26];
int n,m;
vector<vector<char>> v;
int toposort(int s)
{
  int j,r=0,cnt;//cnt表示入度为0的顶点的个数，r表示得到的序列中元素的个数
  int flag=1;//表示排序结束后是否可以得到序列
  for(int i=0; i<n; i++)
      temp[i]=id[i];
  while(s--)
  {
      cnt=0;
      for(int i=0; i<n; i++)
          if(temp[i]==0)
          {
              j=i;//找到入度为0的点的位置
              cnt++;
          }
      if(cnt>=1)
      {
          if(cnt>1) flag=0;//无序
          //cnt==1表示有且只有一个入度为0的顶点,则该顶点必然处于序列最前端
          for(int i=0; i<v[j].size(); i++)
              temp[v[j][i]]--;//删除顶点和出边
          seq[r++]=j+'A';
          temp[j]=-1;
          seq[r]='\0';
      }
      else if(cnt==0)
          return -1;//没有入度为0的点必然存在环
  }
  if(flag) return r;
  else return 0;
}
int main()
{
  int t,k,c;//k用来处理已经处理的关系数，c用来记录当前已经读入的对象数
  int determined;//-1表示关系矛盾，0表示无法得到序列，1表示正常得到序列
  while(~scanf("%d%d",&n,&m)&&(n||m))
  {
      mem(id,0);
      mem(vis,0);
      v.clear();
      v.resize(n);//重新调整大小
      c=0,determined=0;
      for(int i=0; i<m; i++)
      {
          scanf("%s",str);
          int x=str[0]-'A';
          int y=str[2]-'A';
          id[y]++;
          v[x].push_back(y);
          if(!vis[x])//记录读入对象数
          {
              c++;
              vis[x]=1;
          }
          if(!vis[y])
          {
              c++;
              vis[y]=1;
          }
          if(determined==0)
          {
              t=toposort(c);//得到序列中的元素的个数
              if(t==-1)//存在环
			  {
			  	determined=-1;
			  	k=i+1;
			  }
			  else if(t==n)
			  {
			  	determined=1;
			  	k=i+1;
			  }
          }
      }
      if(determined==-1)
          printf("Inconsistency found after %d relations.\n",k);//输出的k是已经成功处理了几个
      else if(determined==0)//无法处理
          printf("Sorted sequence cannot be determined.\n");
      else//输出对应的序列
          printf("Sorted sequence determined after %d relations: %s.\n",k,seq);
  }
  return 0;
}
