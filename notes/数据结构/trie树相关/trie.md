# 数据结构之trie树
```c++
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int son[N][26],cnt[N],idx;
void insert(string s)
{
  int k=0;
  for(int i=0;s[i];i++)
    {
      int u=s[i]-'a';
      if(!son[k][u]) son[k][u]=++idx;
      k=son[k][u];
    }
  cnt[k]++;
}
int query(string s)
{
  int k=0;
  for(int i=0;s[i];i++)
    {
      int u=s[i]-'a';
      if(!son[k][u]) return 0;
      k=son[k][u];
    }
  return cnt[k];
}
int main()
{
  int n;
  cin>>n;
  while(n--)
    {
      char op;
      string s;
      cin>>op>>s;
      if(op=='I') insert(s);
      if(op=='Q') cout<<query(s)<<"\n";
    }
  return 0;
}
```
