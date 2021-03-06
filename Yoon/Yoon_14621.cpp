//蟹幻 照鞠澗 尻蕉
//拭妃 車欠芝 坐亀 嬢巨亜 堂鍵走 乞牽為陥 ば
//衣引 13 蟹身...ばばばばばばば
//https://conkjh032.tistory.com/m/345?category=935025
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M; //俳嘘呪, 亀稽税 鯵呪
vector<char> univ; //害企, 食企
vector<pair<pair<int,int>,int>> edge;
int u, v, d;//u俳嘘人 v俳嘘 d澗 暗軒
//int parent[1000];
vector<int> parent;

int findParent(int v) {
	if (v == parent[v]) {
		return v;
	}
	return parent[v] = findParent(parent[v]);
}

bool sameParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a == b) return true;

	else return false;
}

bool sameGender(int a, int b) {
	if (univ[a] == univ[b]) return false;
	else return true;
}

void Union(int a, int b) {
	a = findParent(a);
	b = findParent(b); 

	if (a > b) parent[a] = b;

	else parent[b] = a;
}

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	return a.second < b.second;
	//distance 搾嘘
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	univ.resize(N + 1); //脊径 神嫌亜蟹辞 達焼左艦 紫戚綜研 1 潅形爽醸陥.
	parent.resize(N + 1);

	// 失紺 脊径
	for (int i = 1; i <= N; i++) {
		cin >> univ[i];
	}
	
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> d;
		edge.push_back(make_pair(make_pair(u,v),d));
	}

	for (int i = 1; i <=N; i++) {
		parent[i] = i;
	}
	sort(edge.begin(), edge.end(), compare);

	int sum = 0;
	//採乞亜 陥牽壱 陥献 失紺戚檎 union, 暗軒 希馬奄.
	for (int i = 0; i < edge.size(); i++) {

		if (!sameParent(edge[i].first.first, edge[i].first.second) 
			&& sameGender(edge[i].first.first,edge[i].first.second)) {
			Union(edge[i].first.first, edge[i].first.second);
			sum += edge[i].second;
		}

	}

	//乞砧 尻衣鞠醸澗走 溌昔
	int p = parent[1];
	for (int i = 1; i <= N; i++) {
		if (findParent(i) != p) {
			cout << -1 << "\n";
			return 0;
		}
	}

	cout << sum << "\n";

	return 0;
}