//11060. ���� ����
#include <iostream>
using namespace std;
int A[1001];
int DP[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		DP[i] = 987654321;
	}
	DP[0] = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= A[i]; ++j) { //������ �� �ִ� ��
			if (i + j >= N) { //������ ���� ��� break
				break;
			}
			if (DP[i + j] > DP[i] + 1) { //i���� j��ŭ �����ؼ� �ѹ��� �Ȱ�����
				DP[i + j] = DP[i] + 1; //�����ؼ� i���� ���� �� + 1
			}
		}
	}
	if (DP[N - 1] == 987654321) { //N-1���� �������� -1 return
		DP[N - 1] = -1;
	}
	cout << DP[N - 1];
	return 0;
}