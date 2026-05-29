#include <bits/stdc++.h>
using namespace std;
const int N=310;
int f[N][N],sum[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>sum[i];
        sum[i]=sum[i-1]+sum[i];
    }
    //先从小区间逐渐扩大到大区间来方便使用
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int l=i,r=i+len-1;
            f[l][r]=0x3f3f3f3f;
            for(int k=l;k<r;k++)
            {
                f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+sum[r]-sum[l-1]);
            }
        }
    }
    cout<<f[1][n];
    return 0;
}
