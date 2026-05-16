# Bellman_Ford(步数限制版)解决最短路问题
```c++
#include <bits/stdc++.h>
using namespace std;
const int N=510,M=1e5+10;
int dist[N],backup[N];
int n,m,k;
struct Eage
{
    int a,b,w;
}eage[M];
bool bellman_ford()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    for(int i=0;i<k;i++)
    {
        memcpy(backup,dist,sizeof dist);
        bool update=false;
        for(int j=0;j<m;j++)
        {
            int a=eage[j].a,b=eage[j].b,w=eage[j].w;
            if(dist[b]>backup[a]+w)
            {
                dist[b]=backup[a]+w;
                update=true;
            }
        }
        if(!update) break;
    }
    if(dist[n]>0x3f3f3f3f>>1) return false;
    return true;
}
int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        eage[i]={a,b,w};
    }
    if(!bellman_ford()) cout<<"impossible";
    else cout<<dist[n];
    return 0;
}
```
*** 
## 注意事项：
- 它和dijkstra不同之处在于它能用来解决负权值问题，dijkstra的局限在在寻找找到最小的值后，就把状态设置为true了，不再改变了
- 这一点在有负权值的题目中是一个缺点，所以选择使用bellman_ford来解决
- 它的特色是一次来更新所有的关系
- 这里还多了一个次数限制，由此引入了backup数组来记录上一次的状态，防止突破步数的限制
- 这里还可以加一个update来优化，在没有数值改变时退出循环
