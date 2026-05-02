//求n的第k位数字: 
n >> k & 1
//返回n的最后一位1：
lowbit(n) = n & -n
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;
ll lowbit(int x)
{
    return x&-x;
}
int main()
{
    int n;
    cin>>n;
   while(n--)
   {
       int x;
       cin>>x;
       int res=0;
       while(x)
       {
           x-=lowbit(x);
           res++;
       }
       cout<<res<<" ";
   }
    return 0;
}
