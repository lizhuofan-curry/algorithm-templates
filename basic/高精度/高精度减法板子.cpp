#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int>&A,vector<int>&B)
{
  if(A.size()!=B.size()) return A.size()>B.size();
  for(int i=A.size()-1;i>=0;i--)
    if(A[i]!=B[i]) return A[i]>B[i];
  return true;
}
vector<int> sub(vector<int>&A,vector<int>&B)
{
  int t=0;
  vector<int>C;
  for(int i=0;i<A.size();i++)
    {
      t=A[i]-t;
      if(i<B.size())t-=B[i];
      C.push_back((t+10)%10);
      if(t<0) t=1;
      else t=0;
    }
  //去除前导0
  while(C.size()>1 && C.back()==0) C.pop_back();
  return C;
}
int main()
{
  string a,b;
  cin>>a>>b;
  vector<int>A,B;
  //将a,b字符串转化为整数数组
  for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
  for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');
  //先比较a和b的大小关系
  if(cmp(A,B))
  {
    //如果a大于b,那么直接调用高精度减法函数
    auto C=sub(A,B);
    for(int i=C.size()-1;i>=0;i--) cout<<C[i];
  }
  else
  {
    //细节问题：
    //如果a小于b,那么先加一个负号，然后再调用sub(B,A)
    auto C=sub(B,A);
    cout<<"-";
    for(int i=C.size()-1;i>=0;i--) cout<<C[i];
  }
  return 0;
}
