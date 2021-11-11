//���� �ȵǴ� ����
//���� �ַ�� ���� ��� Ʋ���� �𸣰ٴ� ��
//��� 13 ����...�ФФФФФФ�
//https://conkjh032.tistory.com/m/345?category=935025
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M; //�б���, ������ ����
vector<char> univ; //����, ����
vector<pair<pair<int,int>,int>> edge;
int u, v, d;//u�б��� v�б� d�� �Ÿ�
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
	//distance ��
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	univ.resize(N + 1); //�Է� ���������� ã�ƺ��� ����� 1 �÷��־���.
	parent.resize(N + 1);

	// ���� �Է�
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
	//�θ� �ٸ��� �ٸ� �����̸� union, �Ÿ� ���ϱ�.
	for (int i = 0; i < edge.size(); i++) {

		if (!sameParent(edge[i].first.first, edge[i].first.second) 
			&& sameGender(edge[i].first.first,edge[i].first.second)) {
			Union(edge[i].first.first, edge[i].first.second);
			sum += edge[i].second;
		}

	}

	//��� ����Ǿ����� Ȯ��
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