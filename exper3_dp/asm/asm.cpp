#include <iostream>
using namespace std;

int ASM(char P[], int m, char T[], int n);
int min(int A, int B, int C);
// 保持原有的常量定义（确保作为编译期常量）
const int m = 5, n = 6;

int main()
{
    char P[m + 1] = "happy", T[n + 1] = "hsppay";
    cout << "最小差别数是：" << ASM(P, m, T, n) << endl;
    return 0;
}

int ASM(char P[], int m, char T[], int n)
{
    int D[6][7];  // 6,7对应m+1，n+1

    for (int j = 1; j <= n; j++)                   // 初始化第0行
        D[0][j] = j;
    for (int i = 0; i <= m; i++)                   // 初始化第0列
        D[i][0] = i;

    for (int j = 1; j <= n; j++)                    // 填写每一列
    {
        for (int i = 1; i <= m; i++)
        {
            // 修正：字符串索引从0开始
            if (P[i - 1] == T[j - 1])
                D[i][j] = min(D[i - 1][j - 1], D[i - 1][j] + 1, D[i][j - 1] + 1);
            else
                D[i][j] = min(D[i - 1][j - 1] + 1, D[i - 1][j] + 1, D[i][j - 1] + 1);
        }
    }
    return D[m][n];                         // 返回最小差别数
}

int min(int A, int B, int C)
{
    int m;
    if (A < B) m = A;
    else m = B;
    if (m > C) m = C;
    return m;
}
 

