# 用dfs解决排列数字问题
```c++
#include <bits/stdc++.h>
using namespace std;
const int N=10;
int path[N],n;
bool st[N];
void dfs(int u)
{
    if(u==n)
    {
        for(int i=0;i<n;i++) cout<<path[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!st[i])
        {
            path[u]=i;
            st[i]=true;
            dfs(u+1);
            st[i]=false;
        }
    }
    return ;
}
int main()
{
    cin>>n;
    dfs(0);
    return 0;
}
```
*** 
## 注意点： 
- dfs主要是利用递归加回溯来解决一系列问题
- 这里的st数组相当于一种状态，它已经被用过了就被打上true的标记，否则就是false
- path则是排列顺序，由于是在for函数中i递增加递归的，所以不走回头路，不会有重复情况
- 还有一个易错点就是在for循环中，我们要用if判断st，用while容易死循环
