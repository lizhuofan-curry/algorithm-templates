#include <bits/stdc++.h>
using namespace std;
const int N=200003;
int h[N],e[N],ne[N],idx;
void insert(int x)
{
    //这样是为了处理负数
    int k=(x%N+N)%N;
     e[idx]=x;
    ne[idx]=h[k];
    h[k]=idx++;
}
bool find(int x)
{
    int k=(x%N+N)%N;
    for(int i=h[k];i!=-1;i=ne[i])
    {
        if(e[i]==x)  return true;
    }
    return false;
}
int main()
{
    //先用拉链法来解决哈希表
    int n;
    cin>>n;
    memset(h,-1,sizeof h);
    while(n--)
    {
        char op;
        int x;
        cin>>op>>x;
        if(op=='I')
        {
            insert(x);
        }
        else
        {
            if(find(x)) cout<<"Yes"<<"\n";
            else cout<<"No"<<"\n";
        }
    }
    return 0;
}
