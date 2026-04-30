#include <bits/stdc++.h>
using namespace std;
//此处用&来引用数组为了避免重新赋值两个数组空间
vector<int> add(vector<int> &A,vector<int> &B)
{
  //确保A数组长度为长的那一个
  if(A.size()<B.size()) return add(B,A);
  vector<int>C;
  int t=0;
  for(int i=0;i<A.size();i++)
    {
      t+=A[i];
      if(i<B.size()) t+=B[i];
      C.push_back(t%10);
      t/=10;
    }
  if(t) C.push_back(t);
  return C;
}
int main()
{
  string a,b;
  vector<int>A,B;
  cin>>a>>b;
  //将字符串数组变成整数数组
  //让个位排在数组首位，以此类推
  for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
  for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');
  //此处用auto自动识别类型
  auto C=add(A,B);
  //C的首位为个位，所以这里输出还是要从数组最高位开始输出最高位
  for(int i=C.size()-1;i>=0;i--) cout<<C[i];
  return 0;
}
