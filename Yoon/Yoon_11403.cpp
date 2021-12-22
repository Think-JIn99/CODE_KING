//���ã��-Floyd-Warshall Algorithm
//�÷��̵� �ͼ� �˰��� ����
//https://ansohxxn.github.io/algorithm/floyd

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100

int N;
int graph[MAX][MAX];

void floyd() {

	for (int k = 0; k < N; k++) { //k�� ���İ��� ����
		for (int i = 0; i < N; i++) { //i�� ��(��� ����)
			for (int j = 0; j < N; j++) { //j�� ��(���� ����)
				if (graph[i][k] && graph[k][j]) { 
					graph[i][j] = 1;
					//i��° �� j��° ���ڰ� 1�ΰ�� i���� j�� ���� ������ �����Ѵٴ� ����
					//�� ������ 1�̸� �׻��̰� ������ �ǹǷ� 1�� �ٲ���...
					//�� �����Ѱ� ������?
				}
			}
		}
	}
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	floyd();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << graph[i][j]<<" ";
		}
		cout << '\n';
	}
}