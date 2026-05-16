#include <bits/stdc++.h>
using namespace std;
const int N=510;
int dist[N],g[N][N];
int n,m;
bool st[N];
int dijkstra()
{
    dist[1]=0;
    for(int i=1;i<=n;i++)
    {
        int t=-1;
        for(int j=1;j<=n;j++)
        {
            if(!st[j] && (t==-1 || dist[t]>dist[j]))
            t=j;
        }
        if(dist[t]==0x3f3f3f3f) break;
        st[t]=true;
        for(int j=1;j<=n;j++)
        {
            dist[j]=min(dist[j],dist[t]+g[t][j]);
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}
int main()
{
    cin>>n>>m;
    memset(dist,0x3f,sizeof dist);
    memset(g,0x3f,sizeof g);
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);
    }
    cout<<dijkstra();
    return 0;
}
