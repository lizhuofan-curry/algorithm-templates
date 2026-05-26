#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int v[N],w[N],f[N][N];
int n,m;
int main()
{
    //01背包问题
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            //不选i的情况
            f[i][j]=f[i-1][j];
            //选i的情况，曲线救国：先把i选了，在再剩下i-1和剩下体积m-v[i]里面去找
            //前提是j要大于等于v[i]
            if(j>=v[i]) f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
        }
    }
    cout<<f[n][m];
    return 0;
}
