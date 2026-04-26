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

#include <iostream>
using namespace std;

const int N = 100010;

int q[N];

// 查找左边界
int findLeft(int q[], int n, int x) {
    int l = 0, r = n - 1;

    while (l < r) {
        int mid = (l + r) >> 1;

        if (q[mid] >= x) r = mid;
        else l = mid + 1;
    }

    if (q[l] == x) return l;
    return -1;
}

// 查找右边界
int findRight(int q[], int n, int x) {
    int l = 0, r = n - 1;

    while (l < r) {
        int mid = (l + r + 1) >> 1;

        if (q[mid] <= x) l = mid;
        else r = mid - 1;
    }

    if (q[l] == x) return l;
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> q[i];

    while (m--) {
        int x;
        cin >> x;

        int left = findLeft(q, n, x);
        int right = findRight(q, n, x);

        cout << left << " " << right << endl;
    }

    return 0;
}
