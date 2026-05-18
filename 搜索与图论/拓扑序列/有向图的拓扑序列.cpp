#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int h[N],e[N],ne[N],idx;
int q[N],d[N];
int n,m;
bool st[N];
void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
bool topu()
{
    int hh=0,tt=0;
    for(int i=1;i<=n;i++)
    if(d[i]==0) q[tt++]=i;
    while(hh<tt)
    {
        int t=q[hh++];
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            d[j]--;
            if(!d[j]) q[tt++]=j;
        }
    }
    return tt==n;
}
int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
        d[b]++;
    }
    if(topu())
    {
        for(int i=0;i<n;i++)
        cout<<q[i]<<" ";
    }
    else cout<<-1;
    return 0;
}
