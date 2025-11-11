#include <iostream>
#include <algorithm>
using namespace std;

int maxsum(int a[], int left, int right); // 函数声明

int main() {
    const int n = 31; // 数组大小需为常量
    // 初始化温度数组t（共30个元素，因为n-1=30）
    int t[n - 1] = { 36,35,35,35,37,33,33,35,32,32,33,35,29,31,35,36,34,27,26,22,24,26,25,23,25,27,27,32,28,29 };
    int a[n - 2]; // 温差数组（30个温度对应29个温差）
    // 计算温差（t[i+1] - t[i]）
    for (int i = 0; i < n - 2; i++) { 
        a[i] = t[i + 1] - t[i];
    }
    int result = maxsum(a, 0, n - 3); // 调用函数计算最大子数组和
    cout << "最显著升温是：" << result << endl; // 输出结果
    return 0;
}

// 分治法计算最大子数组和（用于找最大温差和，即最显著升温）
int maxsum(int a[], int left, int right) {
    if (left == right) {
        return a[left]; // 单个元素时返回自身
    }
    int center = (left + right) / 2;
    // 递归计算左右子数组的最大和
    int leftsum = maxsum(a, left, center);
    int rightsum = maxsum(a, center + 1, right);
    // 计算跨中心的最大和
    int s1 = 0, lefts = 0;
    for (int i = center; i >= left; i--) { // 从中心向左累加
        lefts += a[i];
        if (lefts > s1) s1 = lefts;
    }
    int s2 = 0, rights = 0;
    for (int i = center + 1; i <= right; i++) { // 从中心向右累加
        rights += a[i];
        if (rights > s2) s2 = rights;
    }
    int midsum = s1 + s2;
    // 返回三者中的最大值
    return max({ leftsum, rightsum, midsum });
}
