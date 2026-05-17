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
