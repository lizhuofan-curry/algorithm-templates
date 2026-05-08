#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5;
//ph:插入顺序对应的下标
//hp:下标对应的插入顺序
ll h[N],hp[N],ph[N],siz,n;
void swap_heap(int a,int b)
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}
void down(int x)
{
    int t=x;
    if(2*x <=siz && h[2*x]<h[t]) t=2*x;
    if(2*x +1<=siz && h[2*x+1]<h[t]) t=2*x+1;
    if(t!=x)
    {
        swap_heap(t,x);
        down(t);
    }
}
void up(int x)
{
    while(x/2 && h[x]<h[x/2])
    {
        swap_heap(x,x/2);
        x/=2;
    }
    
}
void insert(int x)
{
    n++;
    siz++;
    ph[n]=siz;
    hp[siz]=n;
    h[siz]=x;
    
}
int main()
{
    int m;
    cin>>m;
    while(m--)
    {
        string s;
        int k,x;
        cin>>s;
        if(s=="I")
        {
            cin>>k;
            insert(k);
            up(siz),down(siz);
        }
        if(s=="PM") cout<<h[1]<<"\n";
        if(s=="DM")
        {
            swap_heap(1,siz);
            siz--;
            down(1);
        }
        if(s=="D")
        {
            cin>>k;
            int pos=ph[k];
            swap_heap(pos,siz);
            siz--;
            up(pos),down(pos);
        }
        if(s=="C")
        {
            cin>>k>>x;
            h[ph[k]]=x;
            up(ph[k]),down(ph[k]);
        }
    }
    return 0;
}
