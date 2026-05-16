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
        for(int j=0;j<m;j++)
        {
            int a=eage[j].a,b=eage[j].b,w=eage[j].w;
            dist[b]=min(dist[b],backup[a]+w);
        }
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
