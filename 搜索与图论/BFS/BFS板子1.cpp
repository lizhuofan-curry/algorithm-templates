#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PLL;
const int N=101;
int s[N][N],d[N][N],n,m; //q[]表示地图，d[]表示经过时的步数
PLL q[N*N]; //q[]表示队列，存入的是数组下标
int bfs()
{
    //从坐标（0,0）开始走
    d[0][0]=0;
    //开始手搓队列
    int hh=0,tt=0,t=0;
    q[0]={0,0};
    int dx[4]={-1,1,0,0} ,dy[4]={0,0,-1,1}; //dx,dy组合起来有上下左右效果
    while(hh<=tt)
    {
        auto item=q[hh++];
        for(int i=0;i<4;i++)
        {
            int x=dx[i]+item.first,y=dy[i]+item.second;
            if(x>=0 && x<n && y>=0 && y<m && d[x][y]==-1 && s[x][y]==0)
            {
                d[x][y]=d[item.first][item.second]+1;
                if(x==n-1 && y==m-1) return d[x][y];
                q[++tt]={x,y};
            }
        }
    }
    return d[n-1][m-1];
}
int main()
{
    cin>>n>>m;
    memset(d,-1,sizeof d);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>s[i][j];
        }
    }
    cout<<bfs()<<"\n";
    return 0;
}
