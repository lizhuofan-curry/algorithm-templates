# 用DFS解决n皇后问题
## 做法1：
```c++
#include <bits/stdc++.h>
using namespace std;
const int N=10;
char q[N][N];
int n;
bool col[N],dg[N],udg[N];
void dfs(int u)
{
    if(u==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<q[i][j];
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    int x=u;
    for(int y=0;y<n;y++)
    {
        if(!col[y] && !dg[y-x+n] &&!udg[x+y])
        {
            q[x][y]='Q';
            col[y]=dg[y-x+n]=udg[x+y]=true;
            dfs(u+1);
            col[y]=dg[y-x+n]=udg[x+y]=false;
            q[x][y]='.';
        }
    }
    return ;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        q[i][j]='.';
    }
    dfs(0);
    return 0;
}
```
***
## 注意事项：
- 这里的倾斜角始终是45度，所以我们利用这个来解决对角线关系
- 我们只要判断纵截距相等即可判断是否在同一对角线上（包括正对角线和反对角线）
- 还有的要注意输出问题比如最后一个没有空格，我们可以用（j==n-1?"":" "）来处理
- 还有一点就是那个col是列，总是和x搞混
- 这种做法总之就是先假固定x，移动y来找一条路，找不到就回溯，知道循环完

## 做法2：
```c++
#include <bits/stdc++.h>
using namespace std;
const int N=10;
char q[N][N];
int n;
bool row[N],col[N],dg[N],udg[N];
void dfs(int x,int y,int s)
{
    if(y==n) x++,y=0;
    if(x==n)
    {
        if(s==n)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<q[i][j];
                }
                cout<<"\n";
            }
            cout<<"\n";
        }
        return ;
    }
    if(!row[x] &&!col[y] && !dg[y-x+n] && !udg[x+y])
    {
        q[x][y]='Q';
        row[x]=col[y]=dg[y-x+n]=udg[x+y]=true;
        dfs(x,y+1,s+1);
        row[x]=col[y]=dg[y-x+n]=udg[x+y]=false;
        q[x][y]='.';
    }
    dfs(x,y+1,s);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        q[i][j]='.';
    }
    dfs(0,0,0);
    return 0;
}
```
## 注意事项：
- 这里采用的是单个比较，相较于上面的做法复杂度大了很多
- 这个做法的巧妙之处在于将s作为循环结束条件，有两个递归来处理符合和不符合的情况
- 所以dfs的题目搜索的方法不止一种，可以多想想
