#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=12,M=1<<N;
ll f[N][M];
int n,m;
bool st[M];
int main()
{
    while(cin>>n>>m,n||m)
    {
        //先来初始化st
        for(int i=0;i<1<<n;i++)
        {
            st[i]=true;
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(i>>j&1)
                {
                    if(cnt&1)
                    {
                        st[i]=false;
                        break;
                    }
                }
                else cnt++;
            }
            if(cnt&1) st[i]=false;
        }
        memset(f,0,sizeof f);
        f[0][0]=1;
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<1<<n;j++)
            {
                for(int k=0;k<1<<n;k++)
                {
                    if((j&k)==0 && st[j|k]) f[i][j]+=f[i-1][k];
                }
            }
        }
        cout<<f[m][0]<<"\n";
    }
}
