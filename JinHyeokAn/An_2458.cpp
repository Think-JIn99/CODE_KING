/*#include <iostream>
using namespace std;

int mat[501][501];

int main() {
	int N, M, st, fi, cnt = 0, count = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> st >> fi;
		mat[st][fi] = 1;
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				if (mat[i][k] == 1 && mat[k][j] == 1)
					mat[i][j] = 1;
			}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (mat[i][j] == 1) cnt++;
			if (mat[j][i] == 1) cnt++;
		}
		if (cnt == N - 1) count++;
		cnt = 0;
	}

	cout << count;
}*/

//Ű ����-�÷��̵� �ͼ�
//�� Ʋ���� �𸣰ڴ� �Ф�

#include <iostream>
#include <algorithm>
//#define MAX 502
//#define INF 987654321
using namespace std;

const int INF = 9999999;
const int MAX = 502;
int N, M;
int a, b;
int graph[MAX][MAX];

void floyd() {

	for (int k = 1; k <= N; k++) { //k�� ���İ��� ����
		for (int i = 1; i <= N; i++) { //i�� ��(��� ����)
			for (int j = 1; j <= N; j++) { //j�� ��(���� ����)
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
				//graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]); 

			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			graph[i][j] = INF;
		}
	}


	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a][b] = 1;
	}

	floyd();

	int result = 0;
	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] != INF || graph[j][i] != INF) {
				cnt++;
			}
		}
		if (cnt == N - 1) {//�ڽ� ���� ��� �� �� ������ �� ����Ǿ��ִٴ� ������
			result++; //Ű�� ���°���� �˼��ִ� ���++
		}
		cnt = 0;
	}
	cout << result << endl;
	return 0;
}