# SPFA处理负环
```c++
#include <bits/stdc++.h>
using namespace std;
const int N=2010,M=1e5+10;
int h[N],e[M],ne[M],w[M],idx;
int dist[N],cnt[N],n,m;
bool st[N];
void add(int a,int b,int c)
{
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}
bool spfa()
{
    //这里不需要设置为真无穷了，因为存在负环的情况的话，都会更新
    queue<int>q;
    //这一步很关键！
    for(int i=1;i<=n;i++)
    {
        q.push(i);
        st[i]=true;
    }
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
                 cnt[j]=cnt[t]+1;
                if(!st[j])
                {
                    st[j]=true;
                    q.push(j);
                }
                if(cnt[j]>=n) return true;
            }
            
        }
    }
    return false;
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
    if(spfa()) cout<<"Yes";
    else cout<<"No";
    return 0;
}
```
****
## 注意事项：
这一有一点***特别值得注意***我debug好久，在临接表中的n[],ne[],w[]都是代表的边，我们有M次输入，所以他们应该开M+个空间！！！  
然后还有要注意的是我们在函数中不用把dist初始化为无穷了，因为存在负环的话，反正会更新的   
嗯还有一点，我们不能从1开始，因为1有可能接不上负环，所以我们一开始要把所有数都接入队列里面去，保证能遍历到负环  
这里判断负环的思想是容斥原理，如果你遍历的边数超过了总边数，而且边数的要求是你变小才更新的，所以一定存在负环！！！
