#include <bits/stdc++.h>
using namespace std;
const int N=200003;
typedef unsigned long long ULL;
ULL p[N],h[N],q=131;
char str[N];
ULL find(int l,int r)
{
    return h[r]-h[l-1]*p[r-l+1];
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    cin>>str+1;
    p[0]=1;
    for(int i=1;i<=n;i++)
    {
        p[i]=p[i-1]*q;
        h[i]=h[i-1]*q+str[i];
    }
    while(m--)
    {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(find(l1,r1)==find(l2,r2)) cout<<"Yes"<<"\n";
        else cout<<"No"<<"\n";
        
    }
}
