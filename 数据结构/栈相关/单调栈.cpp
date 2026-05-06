#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;
ll stk[N],tt=-1;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        while(tt!=-1 && stk[tt]>=x) tt--;
        if(tt==-1) cout<<-1<<" ";
        else cout<<stk[tt]<<" ";
        stk[++tt]=x;
        
    }
    return 0;
}
