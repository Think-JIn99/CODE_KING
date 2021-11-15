#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000
//�༺�� ��� �����ϴµ� �ּҺ���� ���Ѵ�!
//ũ�罺Į �˰��� ���
//ũ�罺Į �˰��� ���� ����
//1. ��� �������� ����ġ�� ������������ ����
//2. ����ġ�� ���� ���� ������ ����
//3. ������ ������ ������ �����Ϸ��� 2���� ��尡 ���� ������� ���� ���¶�� 2�� ��带 ���� ����
//4.�� ������ �ݺ�
int N;
int planet[MAX][MAX];
int parent[MAX], ranks[MAX];


int findParent(int v) { //�θ� ã��
	if (v == parent[v]) {
		return v;
	}

	return parent[v] = findParent(parent[v]);
}

//���� ��ħ
void merge(int a, int b) {
	a = findParent(a);
	b = findParent(b); //a�� b�� �θ� ã��
	//������ ���� �߻�

	if (a != b) { //a�� b�� �θ� �ٸ���
		if (ranks[a] < ranks[b]) {
			swap(a, b);
		}
		parent[b] = a;
		if (ranks[a] == ranks[b]) {
			ranks[a]++;
		}
	}
}

struct Edge { //����ü (����1, ����2, ����ġ), �̰� �ַ��ã�ƺ�...
	int u, v, weight;
	bool operator<(Edge const &e) {
		return weight < e.weight; //�� ���ذ� ���� �ʴ´�..����ü ��ƴ�..
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	//��� �Է¹ޱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> planet[i][j];
		}
	}
	//����1->����2 Ȥ�� ����2->����1 ������ �ϳ��� �Է¹���
	vector<Edge> edge;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			edge.push_back({ i,j,planet[i][j] });
		}
	}
	//������ ����ġ�� ����
	sort(edge.begin(), edge.end());
	//�ʱ�ȭ
	for (int i = 0; i < N; i++) {
		parent[i] = i;
		ranks[i] = 0;
	}

	long long result = 0;
	//���� ����ġ�� �ּҰ��� ����
	for (int i = 0; i < edge.size(); i++) {
		Edge e = edge[i];

		if (findParent(e.u) != findParent(e.v)) {//������ ������ �θ� �ٸ���
			result += e.weight; //e�� ����ġ ������
			merge(e.u, e.v); // ��ħ
		}
	}

	cout << result << "\n";
	return 0;
}