#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
//head指的是头结点，这里的e[]指的是该结点的值，ne[]指的是下一个结点的地址，idx表示地址
int head,e[N],ne[N],idx;
//初始化链表
void init()
{
    //-1表示链表尾部
    head=-1;
    idx=0;
}
//在链表头插入一个数
void add_to_head(int x)
{
    e[idx]=x;
    ne[idx]=head;
    head=idx++;
}
//删除第k个数后面的数
void del(int k)
{
    ne[k]=ne[ne[k]];
}
//在第k个插入的数后面插入一个数x
void insert(int k,int x)
{
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx++;
}
int main()
{
    int m;
    cin>>m;
    init();
    while(m--)
    {
        char a;
        int k,x;
        cin>>a;
        if(a=='H')
        {
            cin>>x;
            add_to_head(x);
        }
        if(a=='D')
        {
            cin>>k;
            //处理特殊情况，在k=0时表示删除头结点
            if(k==0) head=ne[head];
            del(k-1);
        }
        if(a=='I')
        {
            cin>>k>>x;
            insert(k-1,x);
        }
    }
    //打印链表
    for(int i=head;i!=-1;i=ne[i])
    cout<<e[i]<<" ";
    return 0;
}
