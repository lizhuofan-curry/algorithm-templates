#include <bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int q[N];
//快速排序 对q[l~r]这一段进行排序
void quick_sort(int q[],int l,int r)
{
    //退出递归的条件
    if(l>=r) return;
    // i 从左边往右扫，j 从右边往左扫
    int i=l-1,j=r+1;
    //去中间位置数作为基准值
    int x=q[l+r>>1];
    while(i<j)
    {
        //从左往右找第一个>=x的数
        do i++; while(q[i]<x);
        //从右往左找第一个<=x的数
        do j--; while(q[j]>x);
        if(i<j)
        //两边各找到一个后将这两数交换位置
        swap(q[i],q[j]);
    }
    //递归排序左右两边
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}
int main()
{
    //这是快速排序板子
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>q[i];
    }
    quick_sort(q,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<q[i]<<" ";
    }
    return 0;
}
