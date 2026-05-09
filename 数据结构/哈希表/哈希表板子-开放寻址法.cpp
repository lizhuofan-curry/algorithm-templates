#include <bits/stdc++.h>
using namespace std;
const int N=200003,null=0x3f3f3f3f;
int h[N];
int find(int x)
{
    int k=(x%N+N)%N;
    while(h[k]!=null && h[k]!=x) {
        k++;
        if(k==N) k=0;
    }
    return k;
}
int main()
{
    int n;
    cin>>n;
    memset(h,0x3f,sizeof h);
    while(n--)
    {
        char op;
        int x;
        cin>>op>>x;
        if(op=='I')
        {
            h[find(x)]=x;
        }
        if(op=='Q')
        {
            if(h[find(x)]==x) cout<<"Yes"<<"\n";
            else cout<<"No"<<"\n";
        }
    }
    return 0;
}
