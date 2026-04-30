#include <bits/stdc++.h>
using namespace std;
vector<int> mul(vector<int>&A,int b)
{
  vector<int>C;
  int t=0;
  for(int i=0;i<A.size() || t;i++)
    {
      if(i<A.size()) t+=A[i]*b;
      C.push_back(t%10);
      t/=10;
    }
  //删去前导0
  while(C.size()>1 && C.back()==0) C.pop_back();
  return C;
}
int main()
{
  //高精度乘低精度板子
  string a;
  int b;
  cin>>a>>b;
  vector<int>A;
  for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
  auto C=mul(A,b);
  for(int i=C.size()-1;i>=0;i--) cout<<C[i];
  return 0;
}
