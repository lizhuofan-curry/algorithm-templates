#include <bits/stdc++.h>
using namespace std;
const int N=310;
int p[N][N];
int f[N][N];
int n,m;
int dx[4]={-1,0,1,0} ,dy[4]={0,-1,0,1};
int dp(int x,int y)
{
    int &v=f[x][y];
    if(v!=-1) return v;
    v=1;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            int a=x+dx[i],b=y+dy[i];
            if(a>=0 && a<n && b>=0 && b<m && p[x][y]>p[a][b])
            {
                f[x][y]=max(f[x][y],dp(a,b)+1);
            }
        }
    return v;    
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin>>p[i][j];
    int res=0;
    memset(f,-1,sizeof f);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            res=max(res,dp(i,j));
        }
    cout<<res;
    return 0;
}
