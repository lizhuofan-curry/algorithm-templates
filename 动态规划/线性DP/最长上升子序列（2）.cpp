#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int a[N],f[N];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int len=0;
    f[0]=-1e9-10;
    for(int i=1;i<=n;i++)
    {
        int l=0,r=len;
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            //找出小于a[i]最大的数
            if(f[mid]<a[i]) l=mid;
            else r=mid-1;
        }
        f[r+1]=a[i];
        len=max(len,r+1);
    }
    cout<<len;
    return 0;
}
