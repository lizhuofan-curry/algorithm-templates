# 染色法判断二分图（DFS版）
```c++
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=2e5+10;
int h[N],e[M],ne[M],idx;
int color[N];
int n,m;
void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
bool dfs(int x,int c)
{
    color[x]=c;
    for(int i=h[x];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!color[j])
        {
            if(!dfs(j,3^c)) return false;
        }
        else if(color[j]==c) return false;
    }
    return true;
}
int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(!color[i])
        {
            if(!dfs(i,1)) flag=false;
        }
    }
    if(flag==true) cout<<"Yes";
    else cout<<"No";
    return 0;
}
```
*** 
## 注意事项：
- 这里用的是无向图，我们把它视为双向的有向图，所以邻接表注意要开点数的两倍
- 另外我们初始化color数组为0，所以0就当做是未染色，1,2来表示不同颜色
- 其他的思路都比较简单了
