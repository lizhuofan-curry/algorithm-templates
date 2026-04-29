/*
算法名称：二分 Binary Search

适用场景：
1. 在有序数组中查找某个数
2. 查找满足某种条件的边界
3. 常见于“最大值最小”或“最小值最大”问题

核心思想：
每次取中点 mid，根据条件判断答案在左半边还是右半边，
不断缩小区间，直到找到目标位置。

时间复杂度：
O(log n)

常见题型：
AcWing 789. 数的范围

易错点：
1. mid 的写法要注意避免死循环
2. 找左边界和右边界时，更新方式不同
3. while (l < r) 和 while (l <= r) 不能乱混用
*/

bool check(int x) {/* ... */} // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
