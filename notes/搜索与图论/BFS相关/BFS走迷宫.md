# BFS之走迷宫
## 法1（手搓队列）
```c++
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
```
*** 
## 注意事项：
- bfs主要是广度优先遍历，类似于水波那种一层一层的
- 这里的方向向量用的巧妙
- 还能加一个判断进行剪枝优化
- 还有要注意的一点是在判断时x>=0,y>=0，少了等号就麻烦了

## 法2（运用stl queue）
```c++
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PLL;
const int N=101;
int s[N][N],d[N][N],n,m; //q[]表示地图，d[]表示经过时的步数
int bfs()
{
    //从坐标（0,0）开始走
    d[0][0]=0;
    //开始手搓队列
    queue<PLL>q;
    q.push({0,0});
    int dx[4]={-1,1,0,0} ,dy[4]={0,0,-1,1}; //dx,dy组合起来有上下左右效果
    while(q.size())
    {
        auto item=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x=dx[i]+item.first,y=dy[i]+item.second;
            if(x>=0 && x<n && y>=0 && y<m && d[x][y]==-1 && s[x][y]==0)
            {
                d[x][y]=d[item.first][item.second]+1;
                if(x==n-1 && y==m-1) return d[x][y];
                q.push({x,y});
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
```
***
## 注意点：
- 这里用stl和上面手搓队列是一样的
- 只要把h++改成q.pop(),tt++改成q.push,auto item=q[hh]改成q.front();
- 其他的没什么区别
