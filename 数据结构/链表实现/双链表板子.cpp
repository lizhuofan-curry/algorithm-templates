#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int head,fal,e[N],l[N],r[N],idx;
void init()
{
    head=0,fal=1,idx=2;
    r[head]=fal;
    l[fal]=head;
}
void add(int k,int x)
{
    e[idx]=x;
    r[idx]=r[k];
    l[idx]=k;
    l[r[k]]=idx;
    r[k]=idx++;
}
//删除第k个插入的数，我要删第一个的话 idx=2，调用k+1
void del(int k)
{
    l[r[k]]=l[k];
    r[l[k]]=r[k];
}
int main()
{
    int m;
    cin>>m;
    init();
    while(m--)
    {
        int k,x;
        string a;
        cin>>a;
        if(a=="L")
        {
            cin>>x;
            add(head,x);
        }
        if(a=="R")
        {
            cin>>x;
            add(l[fal],x);
        }
        if(a=="D")
        {
            cin>>k;
            del(k+1);
        }
        if(a=="IL")
        {
            cin>>k>>x;
            add(l[k+1],x);
        }
        if(a=="IR")
        {
            cin>>k>>x;
            add(k+1,x);
        }
    }
    //打印双链表
    for(int i=r[head];i!=fal;i=r[i])
    {
        cout<<e[i]<<" ";
    }
    return 0;
}
