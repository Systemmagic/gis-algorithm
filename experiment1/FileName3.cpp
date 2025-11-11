#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// 点结构定义
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

// 按x坐标排序的比较函数
bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}

// 按y坐标排序的比较函数
bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

// 计算两点间距离
double distance(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

// 暴力法计算最近点对（小规模点集）
double bruteForce(const vector<Point>& points, int left, int right) {
    double minDist = numeric_limits<double>::max();
    for (int i = left; i <= right; ++i) {
        for (int j = i + 1; j <= right; ++j) {
            minDist = min(minDist, distance(points[i], points[j]));
        }
    }
    return minDist;
}

// 分治法核心函数（带递归深度控制）
double closestUtil(const vector<Point>& points, int left, int right, int depth) {
    // 限制递归深度（防止异常情况导致栈溢出）
    if (depth > 1000) {
        cerr << "警告：递归深度超过阈值，可能存在逻辑错误" << endl;
        return numeric_limits<double>::max();
    }

    // 小规模点集直接用暴力法
    if (right - left + 1 <= 3) {
        return bruteForce(points, left, right);
    }

    // 计算中间索引（避免整数溢出）
    int mid = left + (right - left) / 2;
    Point midPoint = points[mid];

    // 递归计算左右两部分的最近距离
    double dLeft = closestUtil(points, left, mid, depth + 1);
    double dRight = closestUtil(points, mid + 1, right, depth + 1);
    double minDist = min(dLeft, dRight);

    // 收集距离中间线x坐标小于minDist的点（动态容器，避免栈溢出）
    vector<Point> strip;
    for (int i = left; i <= right; ++i) {
        if (abs(points[i].x - midPoint.x) < minDist) {
            strip.push_back(points[i]);
        }
    }

    // 按y坐标排序（使用标准库排序，稳定且无栈溢出风险）
    sort(strip.begin(), strip.end(), compareY);

    // 检查strip中是否有更近的点对（最多比较每个点后的6个点）
    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j) {
            minDist = min(minDist, distance(strip[i], strip[j]));
        }
    }

    return minDist;
}

// 计算最近点对距离的入口函数
double closestPair(vector<Point>& points) {
    if (points.size() < 2) {
        cerr << "点集数量不足（至少需要2个点）" << endl;
        return 0.0;
    }
    // 按x坐标排序（分治法的前提）
    sort(points.begin(), points.end(), compareX);
    return closestUtil(points, 0, points.size() - 1, 0);
}

// 读取CSV文件中的点坐标
bool readPointsFromCSV(const string& filename, vector<Point>& points) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "错误：无法打开文件 '" << filename << "'" << endl;
        return false;
    }

    string line;
    // 跳过表头（假设第一行是"x,y"）
    if (!getline(file, line)) {
        cerr << "错误：文件为空" << endl;
        file.close();
        return false;
    }

    // 读取数据行
    int lineNum = 1;
    while (getline(file, line)) {
        lineNum++;
        if (line.empty()) continue; // 跳过空行

        stringstream ss(line);
        string xStr, yStr;

        // 解析x坐标
        if (!getline(ss, xStr, ',')) {
            cerr << "警告：第" << lineNum << "行格式错误，跳过" << endl;
            continue;
        }

        // 解析y坐标
        if (!getline(ss, yStr, ',')) {
            cerr << "警告：第" << lineNum << "行格式错误，跳过" << endl;
            continue;
        }

        // 转换为数值
        try {
            double x = stod(xStr);
            double y = stod(yStr);
            points.emplace_back(x, y);
        }
        catch (const exception& e) {
            cerr << "警告：第" << lineNum << "行数值转换失败，跳过 (" << e.what() << ")" << endl;
        }
    }

    file.close();

    if (points.empty()) {
        cerr << "错误：未读取到任何有效点数据" << endl;
        return false;
    }

    cout << "成功读取 " << points.size() << " 个点" << endl;
    return true;
}

int main() {
    vector<Point> points;
    // 文件路径（根据实际情况修改）
    string filename = "D:\\workspace\\visual2022_database\\gis算法设计\\experiment1\\实验一 分治法 二维数据points_2D.csv";

    // 读取点数据
    if (!readPointsFromCSV(filename, points)) {
        return 1; // 读取失败则退出
    }

    // 计算最近点对距离
    double minDistance = closestPair(points);

    // 输出结果
    cout << "最近点对的距离为: " << minDistance << endl;

    return 0;
}