#include <bits/stdc++.h>
using namespace std;
int bfs(string start)
{
    string end="12345678x";
    queue<string> q;
    unordered_map<string,int> d;
    d[start]=0;
    q.push(start);
    while(q.size())
    {
        auto t=q.front();
        if(t==end) return d[end];
        q.pop();
        int k=t.find("x");
        int x=k/3,y=k%3;
        int distans=d[t];
        //方向向量函数
        int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
        for(int i=0;i<4;i++)
        {
            int a=x+dx[i],b=y+dy[i];
            //保证不越界
            if(a>=0 &&a<3 && b>=0 && b<3)
            {
                swap(t[k],t[3*a+b]);
                if(!d.count(t))
                {
                    d[t]=distans+1;
                    q.push(t);
                }
                swap(t[k],t[3*a+b]);
            }
        }
    }
    return -1;
}
int main()
{
    string start;
    for(int i=0;i<9;i++)
    {
        string a;
        cin>>a;
        start+=a;
    }
    cout<<bfs(start);
    return 0;
}
