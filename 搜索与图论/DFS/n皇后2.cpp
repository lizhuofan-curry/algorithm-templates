#include <bits/stdc++.h>
using namespace std;
const int N=10;
char q[N][N];
int n;
bool row[N],col[N],dg[N],udg[N];
void dfs(int x,int y,int s)
{
    if(y==n) x++,y=0;
    if(x==n)
    {
        if(s==n)
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
        return ;
    }
    if(!row[x] &&!col[y] && !dg[y-x+n] && !udg[x+y])
    {
        q[x][y]='Q';
        row[x]=col[y]=dg[y-x+n]=udg[x+y]=true;
        dfs(x,y+1,s+1);
        row[x]=col[y]=dg[y-x+n]=udg[x+y]=false;
        q[x][y]='.';
    }
    dfs(x,y+1,s);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        q[i][j]='.';
    }
    dfs(0,0,0);
    return 0;
}
