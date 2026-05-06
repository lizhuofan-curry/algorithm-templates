#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;
//默认tt=-1，减少边界判断
ll stk[N],tt=-1;
//模拟入栈
void push(int x)
{
    stk[++tt]=x;
}
//模拟出栈
void pop()
{
    tt--;
}
//检查栈是否空
bool empty()
{
    return tt==-1;
}
//查询栈顶元素
ll query()
{
    return stk[tt];
}
int main()
{
    int m;
    cin>>m;
    while(m--)
    {
        int x;
        string a;
        cin>>a;
        if(a=="push")
        {
            cin>>x;
            push(x);
        }
        if(a=="pop")
        pop();
        if(a=="empty")
        {
            if(empty()) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
        if(a=="query")
        cout<<query()<<"\n";
    }
    return 0;
}
