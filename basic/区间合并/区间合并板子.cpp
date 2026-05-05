/*
给定 n个区间 [li,ri]，要求合并所有有交集的区间。
注意如果在端点处相交，也算有交集。
输出合并完成后的区间个数。
例如：[1,3]和 [2,6]可以合并为一个区间 [1,6]
输入格式
第一行包含整数 n,接下来 n行，每行包含两个整数 l和 r
输出格式
共一行，包含一个整数，表示合并区间完成后的区间个数。
数据范围
1≤n≤100000
−109≤li≤ri≤109*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PII;
vector<PII>segs;
vector<PII> merge(vector<PII> &segs)
{
  vector<PII>res;
  ll l=segs[0].first;
  ll r=segs[0].second;
  for(int i=1;i<segs.size();i++)
    {
      auto item=segs[i];
      if(r<item.first) 
        {
          res.push_back({l,r});
          l=item.first;
          r=item.second;
        }
      else 
        r=max(r,item.second);
    }
  res.push_back({l,r});
  segs=res;
  return segs;
}
int main()
{
  int n;
  cin>>n;
  while(n--)
    {
      ll l,r;
      cin>>l>>r;
      segs.push_back({l,r});
    }
  sort(segs.begin(),segs.end());
  merge(segs);
  cout<<segs.size();
  return 0;
}
