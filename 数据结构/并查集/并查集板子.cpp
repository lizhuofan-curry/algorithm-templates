#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int q[N];
int find(int x)
{
  //压缩路径
  if(q[x]!=x) q[x]=find(q[x]);
  return q[x];
}
int main()
{
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++) q[i]=i;
  while(m--)
    {
      char op;
      int a,b;
      cin>>op>>a>>b;
      if(op=='I') q[find(a)]=find(b);
      if(op=='Q') 
      {
        if(find(a)==find(b))
          cout<<"Yes"<<"\n";
        else cout<<"No"<<"\n";
      }
    }
  return 0;
}
