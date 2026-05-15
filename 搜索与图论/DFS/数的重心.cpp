#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int h[2*N],e[2*N],ne[2*N],idx;
int ans=N,n;
bool st[2*N];
//新建联系 （a->b）
void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
int dfs(int u)
{
    int sum=1,res=0;
    st[u]=true;
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!st[j])
        {
            int s=dfs(j);
            res=max(s,res);
            sum+=s;
        }
    }
    res=max(res,n-sum);
    ans=min(res,ans);
    return sum;
}
int main()
{
    cin>>n;
    int m=n-1;
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    dfs(1);
    cout<<ans;
    return 0;
}
