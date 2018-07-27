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
int id[26];//��¼��������
int temp[26];//count�ĸ��ƣ���������ʱ�����޸�
char str[3],seq[26];//seq������¼���յ�����
int vis[26];
int n,m;
vector<vector<char>> v;
int toposort(int s)
{
  int j,r=0,cnt;//cnt��ʾ���Ϊ0�Ķ���ĸ�����r��ʾ�õ���������Ԫ�صĸ���
  int flag=1;//��ʾ����������Ƿ���Եõ�����
  for(int i=0; i<n; i++)
      temp[i]=id[i];
  while(s--)
  {
      cnt=0;
      for(int i=0; i<n; i++)
          if(temp[i]==0)
          {
              j=i;//�ҵ����Ϊ0�ĵ��λ��
              cnt++;
          }
      if(cnt>=1)
      {
          if(cnt>1) flag=0;//����
          //cnt==1��ʾ����ֻ��һ�����Ϊ0�Ķ���,��ö����Ȼ����������ǰ��
          for(int i=0; i<v[j].size(); i++)
              temp[v[j][i]]--;//ɾ������ͳ���
          seq[r++]=j+'A';
          temp[j]=-1;
          seq[r]='\0';
      }
      else if(cnt==0)
          return -1;//û�����Ϊ0�ĵ��Ȼ���ڻ�
  }
  if(flag) return r;
  else return 0;
}
int main()
{
  int t,k,c;//k���������Ѿ�����Ĺ�ϵ����c������¼��ǰ�Ѿ�����Ķ�����
  int determined;//-1��ʾ��ϵì�ܣ�0��ʾ�޷��õ����У�1��ʾ�����õ�����
  while(~scanf("%d%d",&n,&m)&&(n||m))
  {
      mem(id,0);
      mem(vis,0);
      v.clear();
      v.resize(n);//���µ�����С
      c=0,determined=0;
      for(int i=0; i<m; i++)
      {
          scanf("%s",str);
          int x=str[0]-'A';
          int y=str[2]-'A';
          id[y]++;
          v[x].push_back(y);
          if(!vis[x])//��¼���������
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
              t=toposort(c);//�õ������е�Ԫ�صĸ���
              if(t==-1)//���ڻ�
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
          printf("Inconsistency found after %d relations.\n",k);//�����k���Ѿ��ɹ������˼���
      else if(determined==0)//�޷�����
          printf("Sorted sequence cannot be determined.\n");
      else//�����Ӧ������
          printf("Sorted sequence determined after %d relations: %s.\n",k,seq);
  }
  return 0;
}
