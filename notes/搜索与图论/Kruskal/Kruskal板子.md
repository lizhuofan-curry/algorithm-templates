# Kruskal算法求最小生成树问题
```c++
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=2e5+10,INF=0x3f3f3f3f;
int p[N]; //并查集
int n,m;
struct Edge
{
    int a,b,w;
    bool operator < (const Edge &W)const{
        return w<W.w;
    }
}edge[M];
int cnt,res;
int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
bool kruskal()
{
    for(int i=0;i<m;i++)
    {
        int a=edge[i].a,b=edge[i].b,w=edge[i].w;
        a=find(a),b=find(b);
        if(a!=b)
        {
            p[a]=b;
            res+=w;
            cnt++;
        }
    }
    if(cnt<n-1) return false;
    return true;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge[i]={a,b,c};
    }
    sort(edge,edge+m);
    for(int i=1;i<=n;i++) p[i]=i;
    if(kruskal()) cout<<res;
    else cout<<"impossible";
    return 0;
}
```
*** 
## 注意事项：
**这个kruskal算法主要用来处理最小生成树的稀疏图问题，它是利用并查集找祖宗来判断两点是否相连，然后重载了小于号的判断条件**
