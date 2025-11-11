/*#include<iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include<unordered_map>
#include <algorithm>  
using namespace std;

const int n = 122;
const int MAXN = n;  
vector<vector<int>> neibor;  // 全局邻接表
int color[n] = { 0 };
unordered_map<string, string> idToProvince;  // 全局名称映射

int ok(int i);
void graphcolor(int m);
unordered_map<string, string> createDictFromCSV(const string& filePath);
vector<vector<int>> buildAdjacencyTable(const string& filePath);

int main() {
    string filePath = "D:\\workspace\\visual2022_database\\gis算法设计\\实验2_贪心法\\tanxin\\experiment2\\neighbors.csv";
    neibor = buildAdjacencyTable(filePath);  // 全局变量赋值
    string csvPath = "D:\\workspace\\visual2022_database\\gis算法设计\\实验2_贪心法\\tanxin\\experiment2\\provinces.csv";
    idToProvince = createDictFromCSV(csvPath);  // 全局变量赋值

    int m;
    cout << "请输入颜色数：";
    cin >> m;
    graphcolor(m);
    return 0;
}

void graphcolor(int m) {
    int i, j;

    for (i = 0;i < n;i++) {
        color[i] = 0;
    }
    for (i = 0;i >= 0;)
    {
        cout << "处理顶点" << i << "，尝试颜色" << color[i] + 1 << endl;

        color[i] = color[i] + 1;
        while (color[i] <= m && ok(i) == 1)
        {
            color[i] = color[i] + 1;
        }
        if (color[i] > m)
        {
            color[i--] = 0;
        }
        else if (i < n - 1)
        {
            i++;
        }
        else
        {
            for (j = 0;j < n;j++)
            {
                // 补充：显示省份名称（不修改原函数核心逻辑，仅扩展输出）
                string name = idToProvince.count(to_string(j)) ? idToProvince[to_string(j)] : "未知区域";
                cout << "顶点" << j << "（" << name << "）的颜色为" << color[j] << endl;
            }
            return;
        }

    }
	cout << "无解" << endl;
}

int ok(int i)
{
    for (int j = 0;j < i;j++)
    {
        if (neibor[i][j] == 1 && color[i] == color[j])
        {
            return 1;
        }
    }
    return 0;
}

unordered_map<string, string> createDictFromCSV(const string& filePath) {
    unordered_map<string, string> dict;
    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "无法打开文件: " << filePath << endl;
        return dict;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        vector<string> parts;
        string token;
        istringstream tokenStream(line);

        while (getline(tokenStream, token, ',')) {
            parts.push_back(token);
        }

        if (parts.size() == 2) {
            // 补充：去除ID中的空格（避免CSV格式空格导致映射失败）
            string id = parts[0];
            id.erase(remove_if(id.begin(), id.end(), ::isspace), id.end());
            dict[id] = parts[1];
        }
        else {
            cerr << "无效的行格式: " << line << endl;
        }
    }
    return dict;
}

vector<vector<int>> buildAdjacencyTable(const string& filePath) {
    vector<vector<int>> neibor(MAXN, vector<int>(MAXN, 0));

    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "无法打开文件" << endl;
        return neibor;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        istringstream iss(line);
        int src_id, nbr_id;
        char comma;

        if (iss >> src_id >> comma >> nbr_id) {
            if (0 <= src_id && src_id <= MAXN - 1 && 0 <= nbr_id && nbr_id <= MAXN - 1) {
                neibor[src_id][nbr_id] = 1;
                // 双向邻接（不修改原函数逻辑，仅补充必要映射）
                neibor[nbr_id][src_id] = 1;
            }
        }
    }

    file.close();
    return neibor;
}*/