#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int ne[N];
char s1[N],s2[N];
int main()
{
  cin>>s1+1>>s2+1;
  int n=strlen(s1+1);
  int m=strlen(s2+1);
  //生成ne数组
  for(int i=2,j=0;i<=m;i++)
    {
      while(j && s2[i]!=s2[j+1]) j=ne[j];
      if(s2[i]==s2[j+1]) j++;
      ne[i]=j;
    }
  //开始匹配
  for(int i=1,j=0;i<=n;i++)
    {
    while(j && s1[i]!=s2[j+1]) j=ne[j];
    if(s1[i]==s2[j+1]) j++;
    if(j==m)
    {
      cout<<i-m+1<<"\n";
      j=ne[j];
    }
    }
  return 0;
}
