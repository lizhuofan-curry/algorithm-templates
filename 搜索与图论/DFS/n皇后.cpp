#include <bits/stdc++.h>
using namespace std;
const int N=10;
char q[N][N];
int n;
bool col[N],dg[N],udg[N];
void dfs(int u)
{
    if(u==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<q[i][j];
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    int x=u;
    for(int y=0;y<n;y++)
    {
        if(!col[y] && !dg[y-x+n] &&!udg[x+y])
        {
            q[x][y]='Q';
            col[y]=dg[y-x+n]=udg[x+y]=true;
            dfs(u+1);
            col[y]=dg[y-x+n]=udg[x+y]=false;
            q[x][y]='.';
        }
    }
    return ;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        q[i][j]='.';
    }
    dfs(0);
    return 0;
}
