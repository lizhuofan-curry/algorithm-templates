/*
双指针算法的思想：
利用两个指针遍历数组，把朴素算法中的重复扫描压缩为线性扫描。

常见问题：
1. 对于一个序列，用两个指针维护一段满足条件的区间。
2. 对于两个序列，维护某种次序，例如归并排序中合并两个有序序列。
*/
#include <bits/stdc++.h>
using namespace std;

// 根据具体题目替换判断条件。
bool check(const vector<int>& nums, int left, int right)
{
    return nums[left] == nums[right];
}

void two_pointer_template(const vector<int>& nums)
{
    int n = static_cast<int>(nums.size());
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < i && check(nums, j, i)) j++;

        // 在这里处理当前区间 [j, i]。
    }
}

int main()
{
    return 0;
}
