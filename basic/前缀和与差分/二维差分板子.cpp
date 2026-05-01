#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
typedef long long ll;
ll a[N][N],d[N][N];
int main()
{
    ll n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            d[i][j]=a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1];
        }
    }
    while(q--)
    {
        ll x1,y1,x2,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;
        d[x1][y1]+=c;
        d[x2+1][y1]-=c;
        d[x1][y2+1]-=c;
        d[x2+1][y2+1]+=c;
    }
    //最后求一遍前缀和复原变化后的数组
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            a[i][j]=d[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
        
    }
    return 0;
}
