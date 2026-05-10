# 用DFS解决n皇后问题
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
