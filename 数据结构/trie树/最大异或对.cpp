#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=31*N;
typedef long long ll;
ll son[M][2],idx,a[N];
void insert(ll x)
{
    int k=0;
    for(int i=30;i>=0;i--)
    {
        int u=(x>>i)&1;
        if(!son[k][u]) son[k][u]=++idx;
        k=son[k][u];
    }
}
ll search(ll x)
{
    ll k=0,res=0;
    for(int i=30;i>=0;i--)
    {
        ll u=(x>>i)&1;
        if(son[k][!u])
        {
            res=res*2+1;
            k=son[k][!u];
        }
        else
        {
            res=res*2;
            k=son[k][u];
        }
    }
    return res;
}
int main()
{
    ll n,res=0;
    cin>>n;
    while(n--)
    {
        ll x;
        cin>>x;
        insert(x);
        res=max(res,search(x));
    }
    cout<<res;
    return 0;
}
