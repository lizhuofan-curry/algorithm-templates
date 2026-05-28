#include <bits/stdc++.h>
using namespace std;
const int N=510;
int a[N][N],f[N][N];
int main()
{
  //从上至下走
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin>>a[i][j];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=i+1;j++)
        f[i][j]=-1e9;
    f[1][1]=a[1][1];
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
        f[i][j]=max(f[i-1][j],f[i-1][j-1])+a[i][j];
    int res=-1e9;
    for(int i=1;i<=n;i++) res=max(res,f[n][i]);
    cout<<res;
    return 0;
}
