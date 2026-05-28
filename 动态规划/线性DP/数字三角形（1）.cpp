#include <bits/stdc++.h>
using namespace std;
const int N=510;
int a[N][N],f[N][N];
int main()
{
  //从下向上走做法
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin>>a[i][j];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            f[i][j]=-1e9;
    for(int i=1;i<=n;i++) f[n][i]=a[n][i];
    for(int i=n-1;i>=1;i--)
        for(int j=1;j<=i;j++)
        f[i][j]=max(f[i+1][j],f[i+1][j+1])+a[i][j];
    cout<<f[1][1];    
    return 0;
}
