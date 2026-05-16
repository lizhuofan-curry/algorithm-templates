# Dijkstra(堆优化)求最短路径
```c++
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=150010;
int h[N],e[N],ne[N],w[N],idx;
int dist[N],n,m;
bool st[N];
void add(int a,int b,int c)
{
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}
int dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    priority_queue<PII,vector<PII>,greater<PII>>heap;
    dist[1]=0;
    //pair中第一位放距离，第二位放顺序，方便先找最小距离的
    heap.push({0,1});
    while(heap.size())
    {
        auto t=heap.top();
        heap.pop();
        int dis=t.first,var=t.second;
        if(!st[var])
        st[var]=true;
        else continue;
        for(int i=h[var];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>dis+w[i])
            {
                dist[j]=dis+w[i];
                heap.push({dist[j],j});
            }
           
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}
int main()
{
    memset(h,-1,sizeof h);
    cin>>n>>m;
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    cout<<dijkstra();
    return 0;
}
```
***
## 注意事项：
- 堆优化适用于稀疏图，之所以用堆优化是为了方便找到记录最小的那一个数
- 如果遍历的话，则会浪费很多时间，所以我们选择用小根堆来解决
- 这里多了一个权重w的概念
- 嗯在Dijkstra函数中,我们一般先初始化dist为无穷，然后dist[1]=0
- 用优先队列是否为空作为循环结束条件
- 还有一点需要注意的是在找到最小值去更新路径时，我们最好多加一个判断dist[j]>dis+w[i],避免直接引入垃圾值
- 这里的w[i]也是个易错点，经常容易和w[j]弄混淆
- 先来分清楚i和j的区别，j代表的是那一个结点，但是权重是属于这个边的，所以这里的i也意味着idx，不能写反
