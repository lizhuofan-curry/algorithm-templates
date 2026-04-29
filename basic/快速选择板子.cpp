/*
算法名称： 快速选择 quick_select

适用场景：
快速查找数字中第几大的数

核心思想：
在快速排序的基础上，通过算出左区间数字的个数和要查找的数位置比较
确定我要继续查找的区间，来修改递归区间，提高查找效率

经典题型
acwing 786.第k个数
*/
#include <bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int q[N];
int quick_select(int l,int r,int m)
{
    if(l>=r) return q[l];
    int i=l-1,j=r+1,x=q[l+r>>1];
    while(i<j)
    {
        do i++;while(q[i]<x);
        do j--;while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    int num=j-l+1;
    if(m<=num) return quick_select(l,j,m);
    else return quick_select(j+1,r,m-num);
}
int main()
{
    //使用快速选择来解决位置问题
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>q[i];
    cout<<quick_select(0,n-1,k);
    return 0;
}
