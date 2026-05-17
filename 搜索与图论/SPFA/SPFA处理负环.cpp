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
