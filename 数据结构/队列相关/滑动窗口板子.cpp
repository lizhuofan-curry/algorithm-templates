#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main()
{
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    int q[N],tt=-1,hh=0;
    for(int i=0;i<n;i++)
    {
        //去除过期元素，每次只移动一格，所以用if就够了
        if(tt>=hh && i-k+1>q[hh]) hh++;
        //清理没用的元素，这里要找的是最小的，所以把在左边的且小于等于x从队列中删除
        while(tt >=hh &&a[q[tt]] >=a[i]) tt--;
        q[++tt]=i;
        if(i>=k-1) cout<<a[q[hh]]<<" ";
    }
    cout<<"\n";
    tt=-1,hh=0;
    for(int i=0;i<n;i++)
    {
        //去除过期元素，每次只移动一格，所以用if就够了
        if(tt>=hh && i-k+1>q[hh]) hh++;
        //清理没用的元素，这里要找的是最大的，所以把在左边的且小于等于x从队列中删除
        while(tt >=hh && a[q[tt]]<=a[i]) tt--;
        q[++tt]=i;
        if(i>=k-1) cout<<a[q[hh]]<<" ";
    }
    return 0;
}
