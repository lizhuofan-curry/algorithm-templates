#include <bits/stdc++.h>
using namespace std;
const int N=5e4+10;
int p[N*3];
int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
void merge(int x,int y)
{
    //将两集合合并
    p[find(x)]=find(y);
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=3*n;i++) p[i]=i;
    //扩展域来解决此问题，数组大小为3*N
    //1~N来表示同类关系，N+1到2N表示食物，2N+1~3N表示天敌
    int res=0;
    while(k--)
    {
        int d,x,y;
        cin>>d>>x>>y;
        if(x>n ||y>n)
        {
            res++;
            continue;
        }
        if(d==1)
        {
             //判断是否为真
             //如果x吃y或者y吃x就为假
            if(find(x+n)==find(y) || find(y+n)==find(x))
            {
                res++;
                continue;
            }
            //x,y是同类
            merge(x,y);
            //x,y的食物也是同类
            merge(x+n,y+n);
            //x,y的天敌也是同类
            merge(x+2*n,y+2*n);
        }
        if(d==2)
        {
            if(x==y)
            {
                res++;
                continue;
            }
            if(find(x)==find(y) || find(y+n)==find(x))
            {
                res++;
                continue;
            }
            //x的食物是y
            p[find(x+n)]=find(y);
            //y的天敌是x
            merge(y+2*n,x);
            //x的天敌是y的食物
            merge(x+2*n,y+n);
        }
    }
    cout<<res;
    return 0;
}
