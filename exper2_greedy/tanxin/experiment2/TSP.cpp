#include <iostream>
using namespace std;
void solveTSP(int cost[11][11], int n, string name[11], int w);
int main() {
	int n, w;
	// 城市名称数组（11个城市，含一线、二线、三线）
	string name[] = {
		"北京",    // 0：一线
		"上海",    // 1：一线
		"广州",    // 2：一线
		"成都",    // 3：新一线
		"武汉",    // 4：新一线
		"西安",    // 5：新一线
		"青岛",    // 6：二线
		"昆明",    // 7：二线
		"徐州",    // 8：三线
		"洛阳",    // 9：三线
		"长沙"     // 10：新一线
	};

	// 成本矩阵（新增长沙与其他城市的票价，单位：元）
	int cost[11][11] = {
		{0,   553,  862,  690,  520,  515,  326,  1147, 206,  314,  649},   // 北京 → 各地
		{553, 0,    862,  879,  520,  658,  518,  1352, 335,  458,  793},   // 上海 → 各地
		{862, 862,  0,    815,  465,  813,  805,  530,  740,  730,  314},   // 广州 → 各地
		{690, 879,  815,  0,    336,  263,  650,  214,  590,  500,  420},   // 成都 → 各地
		{520, 520,  465,  336,  0,    459,  370,  630,  240,  174,  164},   // 武汉 → 各地
		{515, 658,  813,  263,  459,  0,    520,  525,  390,  174,  504},   // 西安 → 各地
		{326, 518,  805,  650,  370,  520,  0,    1180, 150,  260,  610},   // 青岛 → 各地
		{1147,1352,530,  214,  630,  525,  1180, 0,    980,  860,  500},   // 昆明 → 各地
		{206, 335,  740,  590,  240,  390,  150,  980,  0,    156,  420},   // 徐州 → 各地
		{314, 458,  730,  500,  174,  174,  260,  860,  156,  0,    310},   // 洛阳 → 各地
		{649, 793,  314,  420,  164,  504,  610,  500,  420,  310,  0}     // 长沙 → 各地
	};
	 n = 11; // 城市数量	
	 w = 10; // 长沙编号
	solveTSP(cost, n, name, w);
	return 0;
}

void solveTSP(int cost[11][11], int n, string name[11], int w) {
	cout << "Solving TSP using a tanxin algorithm..." << endl;
	// Implementation of TSP algorithm goes here
	int totalCost = 0, edgeCount = 0, u, v, j, min, flag[11] = {0};
	u = w,flag[w] = 1;
	while (edgeCount < n)
	{
		min = 999;
		for(j = 0; j < n; j++)
		{
			if(cost[u][j] < min && cost[u][j] != 0 && flag[j] == 0)
			{
				min = cost[u][j];
				v = j;
			}
			cout << "From city " << name[u] << " to city " << name[v] << " with cost " << min << endl;
			flag[v] = 1,edgeCount++;
			totalCost += min;
			u = v;
		}
	}
	cout << "From city " << name[u] << " to city " << name[w] << " with cost " << cost[u][w] << endl;
	totalCost += cost[u][w];
	cout << totalCost;
}


