#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll a[N],sum[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    //求前缀和
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<"\n";
    }
    return 0;
}
