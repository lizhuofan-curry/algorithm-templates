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
