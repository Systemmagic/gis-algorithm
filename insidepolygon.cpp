#include <stdbool.h>  // 用于bool类型

typedef struct {
    int x, y;
} Point;

// 判断点P是否在多边形V（含n个顶点）内部
// 返回值：非0表示在内部，0表示在外部（winding number算法）
int cn_PnPoly(Point P, Point V[], int n) {
    int wn = 0;  // 绕数初始化为0

    // 遍历多边形的所有边（V[i]到V[i+1]，最后一条边是V[n-1]到V[0]）
    for (int i = 0; i < n; i++) {
        Point Vi = V[i];
        Point Vj = V[(i + 1) % n];  // 下一个顶点，形成闭合多边形

        // 规则1：边向上穿过y=P.y（Vi.y <= P.y < Vj.y）
        if (Vi.y <= P.y && Vj.y > P.y) {
            // 计算点P是否严格在边ViVj的左侧（叉积判断）
            // 叉积 (Vj - Vi) × (P - Vi) > 0 表示在左侧
            int cross = (Vj.x - Vi.x) * (P.y - Vi.y) - (Vj.y - Vi.y) * (P.x - Vi.x);
            if (cross > 0) {
                wn++;  // 绕数+1
            }
        }
        // 规则2：边向下穿过y=P.y（Vj.y <= P.y < Vi.y）
        else if (Vj.y <= P.y && Vi.y > P.y) {
            // 计算点P是否严格在边ViVj的右侧（叉积判断）
            // 叉积 (Vj - Vi) × (P - Vi) < 0 表示在右侧
            int cross = (Vj.x - Vi.x) * (P.y - Vi.y) - (Vj.y - Vi.y) * (P.x - Vi.x);
            if (cross < 0) {
                wn--;  // 绕数-1
            }
        }
        // 忽略与y=P.y共线或不穿过的边
    }

    return wn;  // 返回绕数（非0表示在内部）
}