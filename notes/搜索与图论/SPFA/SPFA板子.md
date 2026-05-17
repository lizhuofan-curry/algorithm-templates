# 用SPFA求最短路径
```c++
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int h[N],e[N],ne[N],w[N],idx;
int dist[N],n,m;
bool st[N];
void add(int a,int b,int c)
{
    w[idx]=c;
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
    
}
bool spfa()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    queue<int> q;
    q.push(1);
    while(q.size())
    {
        int t=q.front();
        st[t]=false;
        q.pop();
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>dist[t]+w[i])
            {
                dist[j]=dist[t]+w[i];
                if(!st[j])
                {
                    st[j]=true;
                    q.push(j);
                }
            }
        }
    }
    if(dist[n]>0x3f3f3f3f>>1) return false;
    return true;
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
    if(spfa()) cout<<dist[n];
    else cout<<"impossible";
    return 0;
}
```
*****
## 注意事项：
- 说实话SPFA给我的感觉就像是将dijkstra（堆优化版）和bellman_ford融合起来
为什么这样说呢，先来说bellman_ford吧，它是在bellman_ford的基础上进行了优化，bellman_ford是无脑遍历整个路径，无论你有没有改变，这样虽然能解决问题，但是很低效
所以sfpa在这方面进行了优化，它会先判断你有没有发生改变，你没有改变的话，那你后面的也不会变化了，大大提高了效率，那么问题来了，我们要如何记录有没有改变和继续遍历它后面的数呢
这时的思想和dijkstra就很像了，用临接表加队列来实现，加一个有没有在队列中的st状态变量，如果改变且不在队列中则加入队列去改变后面的数
