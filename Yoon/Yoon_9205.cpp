//9205.���� ���ø鼭 �ɾ��-DFS

#include <iostream>
#include <vector>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 100 + 2;
int t;
int n;
float x, y;
bool visited[MAX]; 
vector<int> map[MAX]; //���� ǥ�õ� �׷���

//����ư �Ÿ�: �� ��ǥ ������ �Ÿ��� x��ǥ�� ���� + y��ǥ�� ����
int distance(pair<int, int>v1, pair<int, int>v2) {
	return abs(v1.first - v2.first) + abs(v1.second - v2.second);
}

void DFS(int n) {
	visited[n] = true;

	for (int i = 0; i < map[n].size(); i++) {
		int next = map[n][i];
		if (visited[next] == false) { //�湮���� �ʾ����� DFS
			DFS(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t; //�׽�Ʈ ���̽�

	for(int i=0;i<t;i++) { //map�� visited �ʱ�ȭ
		for (int j = 0; j < MAX; j++) {
			map[j].clear();
		}
		memset(visited, false, sizeof(visited));

		cin >> n; //������ ����
		vector<pair<int, int>> xygraph; //��ǥ ����

		for (int j = 0; j < n + 2; j++) {
			cin >> x >> y;
			xygraph.push_back(make_pair(x, y));
		}

		for (int j = 0; j < n + 2; j++) {
			for (int k = j + 1; k < n + 2; k++) {
				if (distance(xygraph[j], xygraph[k]) <= 50 * 20) {
					//���� 1������ 50m �� �� �ְ�, �ִ� 20������ ������ ���� �� �����ϱ�
					//�ѹ��� 1000m���� �� �� ����
					//����� �׷����� �������
					map[j].push_back(k);
					map[k].push_back(j);
				}
			}
		}
		DFS(0);
		//�������� n+1�� �� �� ������
		if (visited[n + 1]==1) {
			cout << "happy\n";
		}
		else
			cout << "sad\n";
	}
	return 0;
}