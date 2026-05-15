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
int bfs(int u)
{
    //表示还没走过
   memset(d,-1,sizeof d);
   int hh=0,tt=0;
   q[0]=1;
   d[1]=0;
   while(hh<=tt)
   {
       int t=q[hh++];
       for(int i=h[t];i!=-1;i=ne[i])
       {
           int j=e[i];
           if(d[j]==-1)
           {
               d[j]=d[t]+1;
               q[++tt]=j;
           }
       }
   }
   return d[n];
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
    }
    cout<<bfs(1);
    
    return 0;
}
