#include <bits/stdc++.h>
using namespace std;
const int N=1010,mod=1e9+7;
int f[N][N];
int n;
int main()
{
    cin>>n;
    f[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=n;j++)
        {
            f[i][j]=f[i-1][j];
            if(j>=i) f[i][j]=(f[i][j]+f[i][j-i])%mod;
        }
    cout<<f[n][n];    
    return 0;
}
