# 数据结构之KMP算法
```c++
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
    for(int i=1;i<=m;i++) cout<<ne[i]<<" ";
  return 0;
}
```
*** 
## 注意点：  
- 很多初学者一开始就被ne数组劝退了，不太理解它的生成过程
- 我昨天思考了好久，发现它和匹配的过程是一样的
- 只是生成ne数组的过程是自身和自身匹配，匹配的过程是自己和别人匹配
- 理解就这一点kmp差不多就掌握了
- 还有一点就是注意只有while循环时要判断匹配成功数是否为0
- 那个cin>>时如果是从第一位开始的，那么strlen也要strlen(s1+1),这样才准确
