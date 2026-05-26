#include <bits/stdc++.h>
using namespace std;
const int N=25000;
int v[N],w[N];
int f[N];
int n,m;
int main()
{
    //用二进制将多重背包转化为01背包问题
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int a,b,s;
        cin>>a>>b>>s;
        int k=1;
        while(k<=s)
        {
            cnt++;
            v[cnt]=k*a;
            w[cnt]=k*b;
            s-=k;
            k*=2;
        }
        if(s)
        {
            cnt++;
            v[cnt]=s*a;
            w[cnt]=s*b;
        }
    }
    //现在变成01背包问题了
    n=cnt;
    for(int i=1;i<=n;i++)
        for(int j=m;j>=v[i];j--)
            f[j]=max(f[j],f[j-v[i]]+w[i]);
    cout<<f[m];        
    return 0;
}
