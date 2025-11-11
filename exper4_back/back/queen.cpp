
/*#include<iostream>
#include<cmath>  
using namespace std;

// 判断第i行的皇后是否与前i-1行的皇后冲突（1冲突，0不冲突）
int Place(int x[], int i) {
    int j;
    for (j = 1; j < i; j++) { 
        // 若同列或同对角线则冲突
        if (x[i] == x[j] || abs(i - j) == abs(x[i] - x[j])) {
            return 1;  
        }
    }
    return 0;  
}

void Queen(int x[], int n) {
    int i, j;
    // 初始化数组（皇后从第1行开始放，x[i]表示第i行皇后的列号）
    for (i = 1; i <= n; i++) {
        x[i] = 0;
    }
    i = 1;  
    while (i > 0) 
    {  
        x[i]++;   
        if (!Place(x, i) && x[i] <= n) { 
            if (i == n)
            {  
                break;
            }
            i++;
        }
        else {
            // 若冲突或列号超界
            if (x[i] > n) {
                x[i] = 0;
                i--;
            }
        }
    }
    if (i == 0) {
        cout << n << "皇后问题无解" << endl;
    }
    else if (i == n) {
        if (!Place(x, n))
        {
            cout << n << "皇后问题有解" << endl;
            for (j = 1; j <= n; j++) 
            {  
                cout << "皇后" << j << "放置于第" << j << "行第" << x[j] << "列" << endl;
            }
        }
        else {
            cout << n << "皇后问题无解" << endl;
        }
    }
}

// 测试函数
int main() {
    int n;
    cout << "请输入皇后数量n：";
    cin >> n;
    int* x = new int[n + 1];  // 动态分配数组（1~n行）
    Queen(x, n);
    delete[] x;  // 释放内存
    return 0;
}
*/