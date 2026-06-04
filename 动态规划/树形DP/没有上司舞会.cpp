#include <bits/stdc++.h>
using namespace std;
const int N=6010;
int n,happy[N];
int f[N][2];
int h[N],e[N],ne[N],idx;
bool is_son[N];
void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
void dp(int x)
{
    f[x][1]=happy[x];
    for(int i=h[x];i!=-1;i=ne[i])
    {
        int j=e[i];
        dp(j);
        f[x][0]+=max(f[j][0],f[j][1]);
        f[x][1]+=f[j][0];
    }
    
}
int main()
{
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++) cin>>happy[i];
    for(int i=1;i<n;i++)
    {
        int a,b;
        //b是a的上司
        cin>>a>>b;
        add(b,a);
        is_son[a]=true;
    }
    int root=0;
    for(int i=1;i<=n;i++) if(!is_son[i]) root=i;
    dp(root);
    cout<<max(f[root][1],f[root][0]);
    return 0; 
}
