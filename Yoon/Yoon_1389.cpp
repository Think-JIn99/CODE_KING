//�ɺ� �������� 6�ܰ� ��Ģ-�÷��̵� �ͼ�

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

const int INF = 987654321;

int N, M; //������ ��, ģ�� ������ ��
int A, B;
int graph[MAX][MAX];

void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;

				else if (graph[i][k] && graph[k][j]) {
					if (graph[i][j] == 0) {
						graph[i][j] = graph[i][k] + graph[k][j]; //������ ��
					}
					else
						graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]); //�� ���� ������ ���� 
				}
			}
		}
	}
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		graph[A][B] = graph[B][A] = 1;
	}

	floyd();

	int result = INF;
	int person=0;

	for (int i = 1; i <= N; i++) {
		int sum = 0;

		for (int j = 1; j <= N; j++) {
			sum += graph[i][j]; //i�� ������ ���� ������
		}

		if (result > sum) {
			result = sum; //sum(�� ������ ��)�� ���� ���� ��
			person = i;
		}
	}
	cout << person << '\n';
	return 0;
}
