#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int v[N],w[N],f[N];
int n,m;
int main()
{
    //01背包问题（优化版）
    //注意到每次的状态都只和上次有关，不妨去掉其中一个维度
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=v[i];j--)
        {
            //选i的情况，曲线救国：先把i选了，在再剩下i-1和剩下体积m-v[i]里面去找
            //前提是j要大于等于v[i]
            if(j>=v[i]) f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    cout<<f[m];
    return 0;
}
