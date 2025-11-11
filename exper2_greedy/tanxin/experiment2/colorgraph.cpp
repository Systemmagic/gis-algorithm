/*#include<iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include<unordered_map>
using namespace std;
const int MAXN = 122;

// 函数声明
unordered_map<string, string> createDictFromCSV(const string& filePath);
vector<vector<int>> buildAdjacencyTable(const string& filePath);
int colorgraph(const vector<vector<int>>& neibor, int color[MAXN]);

// 主函数
int main() {
    string filePath = "D:\\workspace\\visual2022_database\\gis算法设计\\实验2_贪心法\\tanxin\\experiment2\\neighbors.csv"; // 替换为实际的文件路径
    vector<vector<int>> neibor = buildAdjacencyTable(filePath);
    string csvPath = "D:\\workspace\\visual2022_database\\gis算法设计\\实验2_贪心法\\tanxin\\experiment2\\provinces.csv";
    unordered_map<string, string> myDict = createDictFromCSV(csvPath);

    int color[MAXN] = { 0 };
    int k = colorgraph(neibor, color);
    cout << "一共需要" << k << "种颜色" << endl;
    for (int i = 0; i < MAXN; i++)
    {
        string string_i = to_string(i);
        cout << "节点 " << myDict[string_i] << " 的颜色是: " << color[i] << endl;
    }
}

// 从CSV文件创建ID-名称映射字典
unordered_map<string, string> createDictFromCSV(const string& filePath) {
    unordered_map<string, string> dict;
    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "无法打开文件: " << filePath << endl;
        return dict;
    }

    string line;
    // 跳过表头
    getline(file, line);

    while (getline(file, line)) {
        // 拆分当前行的key和value
        vector<string> parts;
        string token;
        istringstream tokenStream(line);

        // 按逗号分割当前行
        while (getline(tokenStream, token, ',')) {
            parts.push_back(token);
        }

        // 校验格式并插入字典
        if (parts.size() == 2) {
            dict[parts[0]] = parts[1];
        }
        else {
            cerr << "无效的行格式: " << line << endl;
        }
    }
    return dict;
}

// 从CSV文件构建邻接表
vector<vector<int>> buildAdjacencyTable(const string& filePath) {
    // 创建一个 MAXNxMAXN 的全零数组
    vector<vector<int>> neibor(MAXN, vector<int>(MAXN, 0));

    // 打开文件
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "无法打开文件" << endl;
        return neibor;
    }

    // 跳过表头行
    string line;
    getline(file, line);

    while (getline(file, line)) {
        istringstream iss(line);
        int src_id, nbr_id;
        char comma;

        // 解析每一行的数据
        if (iss >> src_id >> comma >> nbr_id) {
            // 如果源 ID 和相邻 ID 都在 0 到 120 的范围内
            if (0 <= src_id && src_id <= MAXN - 1 && 0 <= nbr_id && nbr_id <= MAXN - 1) {
                // 将对应位置设为 1，表示相邻
                neibor[src_id][nbr_id] = 1;
            }
        }
    }

    file.close();
    return neibor;
}

// 图着色算法
int colorgraph(const vector<vector<int>>& neibor, int color[MAXN]) {
    int i, j, k = 0, flag = 1;
    while (flag == 1)
    {
        k++, flag = 0;
        for (i = 0; i < MAXN; i++)
        {
            if (color[i] != 0) continue;
            color[i] = k;
            for (j = 0; j < MAXN; j++)
            {
                if (neibor[i][j] == 1 && color[j] == color[i])
                {
                    break;
                }
            }
            if (j < MAXN)
            {
                color[i] = 0, flag = 1;
            }
        }
    }
    return k;
}
*/
