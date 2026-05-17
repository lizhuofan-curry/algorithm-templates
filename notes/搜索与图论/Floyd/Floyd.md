# 用Floyd来解决最短路问题
```c++
#include <bits/stdc++.h>
using namespace std;
const int N=210,INF=0x3f3f3f3f;
int n,m,k;
int dist[N][N];
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c);
    }
    floyd();
    while(k--)
    {
        int x,y;
        cin>>x>>y;
        int t=dist[x][y];
        if(t>INF>>1) cout<<"impossible"<<"\n";
        else cout<<dist[x][y]<<"\n";
    }
    return 0;
}
```
***** 
## 注意事项：
- 这个Floyd算法核心思想是动态规划，我目前进度还没到那，只能先背着
- 嗯先写一个注意点吧，三层循环中的最外层循环注意写k,然后才到i，j
- 哦floyd函数中的k与全局变量k并不冲突， 这是 C++ 的作用域规则：内层优先，互不干扰。
