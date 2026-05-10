#include <bits/stdc++.h>
using namespace std;
const int N=10;
int path[N],n;
bool st[N];
void dfs(int u)
{
    if(u==n)
    {
        for(int i=0;i<n;i++) cout<<path[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!st[i])
        {
            path[u]=i;
            st[i]=true;
            dfs(u+1);
            st[i]=false;
        }
    }
    return ;
}
int main()
{
    cin>>n;
    dfs(0);
    return 0;
}
