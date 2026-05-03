#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int N=3e5+10;
ll a[N],s[N];
vector<PII> add,query;
vector<ll> all;
ll find(ll x)
{
    int l=0,r=all.size()-1;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(all[mid]>=x) r=mid;
        else l=mid+1;
    }
    //因为后面是要用前缀和，所以数组从一开始排
    return r+1;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        ll x,c;
        cin>>x>>c;
        add.push_back({x,c});
        all.push_back(x);
    }
    for(int i=0;i<m;i++)
    {
        ll l,r;
        cin>>l>>r;
        query.push_back({l,r});
        all.push_back(l);
        all.push_back(r);
    }
    //先排序再映射
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    for(auto item:add)
    {
        ll x=find(item.first);
        a[x]+=item.second;
    }
    for(int i=1;i<=all.size();i++) s[i]=s[i-1]+a[i];
    for(auto item: query)
    {
        ll l=find(item.first);
        ll r=find(item.second);
        cout<<s[r]-s[l-1]<<"\n";
    }
    return 0;
}
