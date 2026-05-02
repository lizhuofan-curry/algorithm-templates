/*
给定两个升序排序的有序数组 A和 B，以及一个目标值 x
数组下标从 0开始。
请你求出满足 A[i]+B[j]=x的数对 (i,j)数据保证有唯一解。
输入格式
第一行包含三个整数 n,m,x，分别表示 A的长度，B的长度以及目标值 x
第二行包含 n个整数，表示数组 A的长度
第三行包含 m个整数，表示数组 B的长度
输出格式
共一行，包含两个整数 i和 j
数据范围
数组长度不超过 105
同一数组内元素各不相同。
1≤数组元素≤109
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll a[N],b[N];
int main()
{
  int n,m,x;
  cin>>n>>m>>x;
  for(int i=0;i<n;i++) cin>>a[i];
  for(int j=0;j<m;j++) cin>>b[j];
  int i=0,j=m-1;
  while(i<n && j>=0)
    {
      if(a[i]+b[j]==x) break;
      else if(a[i]+b[j]>x) j--;
      else i++;
    }
  cout<<i<<" "<<j;
  return 0;
}
