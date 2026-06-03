# 状态压缩之最短Hamilton路径
```c++
#include <bits/stdc++.h>
using namespace std;
const int N=20,M=1<<N;
int w[N][N],f[M][N];
int n;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>w[i][j];
    memset(f,0x3f,sizeof f);        
    f[1][0]=0;        
    for(int i=0;i<1<<n;i++)
        for(int j=0;j<n;j++)
            if((i>>j)&1)
                for(int k=0;k<n;k++)
                    if((i-(1<<j))>>k & 1)
                        f[i][j]=min(f[i][j],f[i-(1<<j)][k]+w[k][j]);
    cout<<f[(1<<n)-1][n-1];                    
    return 0;
}
```
## 做法：
通过这两道状态压缩题，我发现了状态压缩主要是用二进制来进行压缩的   
这里呢我们f[i][j]中的i用二进制表示n位数1则是已经走过了，0则是没有走过 ，j是最后一个到达的数  
第一重循环是循环每一个走过的状态  
第二重循环是遍历每一个数，枚举当前停在哪个点   
那个判断是为了确定你停的这个点一定在我们走过的路径里面  
第三层循环是找到j前面那个点，来寻找最短的情况  
注意你除去j这个数位后，还得判断第k位是否存在在路径中    
还有一个易错点记得初始化f为0x3f
