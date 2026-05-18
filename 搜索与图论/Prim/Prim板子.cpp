#include <bits/stdc++.h>
using namespace std;
const int N=510,INF=0x3f3f3f3f;
int g[N][N],dist[N];
bool st[N];
int n,m;
int prim()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int t=-1;
        for(int j=1;j<=n;j++)
        {
            if(!st[j] && (t==-1 || dist[t]>dist[j]))
            t=j;
        }
        st[t]=true;
        if(dist[t]==INF) return INF;
        res+=dist[t];
        for(int j=1;j<=n;j++)
        {
            dist[j]=min(dist[j],g[t][j]);
        }
    }
    return res;
}
int main()
{
    //prim做法和dijkstra朴素版做法差不多
    cin>>n>>m;
    memset(g,0x3f,sizeof g);
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        //由于最小生成树一般都是无向图所以我们在插入时一般加两条边
        g[a][b]=g[b][a]=min(g[a][b],c);
    }
    int t=prim();
    if(t>INF>>1) cout<<"impossible";
    else cout<<t;
    return 0;
}
