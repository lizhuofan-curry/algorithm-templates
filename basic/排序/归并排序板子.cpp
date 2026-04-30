/*
算法名称：归并排序 merge_sort

适用场景：
1.给无序数组排序
 
核心思想：
先分区间，给每个区间排好序
再将左右两个区间融合到一起

常见题型：
acwing 787.归并排序
*/
#include <bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int q[N],tem[N];
void merge_sort(int q[],int l,int r)
{
    if(l>=r) return;
    //先分为两部分
    int mid=l+r>>1;
    merge_sort(q,l,mid);
    merge_sort(q,mid+1,r);
    //再将这两部分合并为一个数组
    int i=l,j=mid+1,k=0;
    while(i<=mid && j<=r)
    {
        if(q[i]<q[j]) tem[k++]=q[i++];
        else tem[k++]=q[j++];
    }
    while(i<=mid) tem[k++]=q[i++];
    while(j<=r) tem[k++]=q[j++];
    //最后将临时数组复制到原数组中去
    for(int i=l,j=0;i<=r;i++,j++)
    {
        q[i]=tem[j];
    }
}
int main()
{
    //继续练习归并排序
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>q[i];
    merge_sort(q,0,n-1);
    for(int i=0;i<n;i++) cout<<q[i]<<" ";
    return 0;
}
