//2502. ���Դ� ȣ����
#include <iostream>
using namespace std;
int DP[31][2]; //DP[��¥][A or B]

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int D, K; //�ҸӴϰ� �Ѿ�� ��, ȣ���̿��� �� �� ����
	int A, B;
	cin >> D >> K;
	
	DP[1][0] = 1;
	DP[2][1] = 1;

	for (int i = 3; i <= 31; i++) {
		DP[i][0] = DP[i - 2][0] + DP[i - 1][0]; //A
		DP[i][1] = DP[i - 2][1] + DP[i - 1][1]; //B
	}

	for (int i = 1; i < 10000; i++) {
		for (int j = 1; i < 10000; j++) {
			if (i * DP[D][0] + j * DP[D][1] == K) {
				cout << i << "\n" << j;
				return 0;
			}
			if (i * DP[D][0] + j * DP[D][1] > K) {
				break;
			}
		}
	}




	return 0;
}