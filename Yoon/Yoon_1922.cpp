//��Ʈ��ũ ����
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100000

int parent[MAX];
int N, M;
vector<pair<pair<int, int>, int>> computer;
int ans = 0;


int findParent(int v) {
	if (parent[v] == v) return v;
	return parent[v] = findParent(parent[v]);
}

bool sameParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a == b) return true;

	else return false;
}

void Union(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a > b) parent[a] = b;
	else parent[b] = a;
}

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	return a.second < b.second;
	//��� ��
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M; //��ǻ�� ��, ������ �� �ִ� ���� ��

	int a, b, c; //��1 ��2 ���
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		computer.push_back(make_pair(make_pair(a, b), c));
	}
	for (int i = 0; i < MAX; i++) {
		parent[i] = i;
	}
	sort(computer.begin(), computer.end(),compare);
	for (int i = 0; i < M; i++) {
		if (sameParent(computer[i].first.first, computer[i].first.second) == false) {
			Union(computer[i].first.first, computer[i].first.second);
			ans = ans + computer[i].second;
		}
	}
	cout << ans << '\n';
	return 0;
}

// ũ�罺Į�� �˰��ִ´�� Ǯ������ ���� 35�� ���ͼ� Ʋ�ȴ�.��
// ���鼭 Ǯ� sort�� �����༭ Ʋ���ſ���... �ʹ� ������..
