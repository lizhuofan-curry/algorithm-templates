#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int d[N],n,m;
void down(int x)
{
    int t=x;
    if( 2*x<=n && d[2*x]<d[t]) t=2*x;
    if( 2*x+1<=n && d[2*x+1]<d[t]) t=2*x+1;
    if(x!=t)
    {
        swap(d[x],d[t]);
        down(t);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++ ) cin>>d[i];
    for(int i=n/2;i>=1;i--)
    {
        down(i);
    }
    //输出逻辑：d[2],d[3]是d[1]的子节点，没有大小关系
    //所以是用最后一个最大的元素覆盖第一个元素，将总数--，再下沉得到新的最小值
    while(m--)
    {
        cout<<d[1]<<" ";
        d[1]=d[n];
        n--;
        down(1);
    }
    return 0;
}
