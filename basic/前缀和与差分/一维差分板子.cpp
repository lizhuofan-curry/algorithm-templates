#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef long long ll;
ll a[N],d[N];
int main()
{
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    for(int i=1;i<=n;i++)
    d[i]=a[i]-a[i-1];
    while(m--)
    {
        ll l,r,c;
        cin>>l>>r>>c;
        d[l]+=c;
        d[r+1]-=c;
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=a[i-1]+d[i];
        cout<<a[i]<<" ";
    }
    return 0;
}
