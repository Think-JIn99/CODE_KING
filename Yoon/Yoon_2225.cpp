//2225. �պ���
#include <iostream>
#define MAX 201
#define mod 1000000000
using namespace std;

int main() {

	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);

	int N, K;
	long long arr[MAX][MAX] = { 0 };
	//
	cin >> N >> K;

	for (int i = 0; i <= K; i++) {
		arr[1][i] = i; //N�� 1�϶� ���� �ɼ� �ִ� ����� K��
	}
	for (int n = 2; n <= N; n++) { //�ΰ� �̻� ���Ҷ�
		for(int k = 1; k <= K; k++){
			arr[n][k] = (arr[n-1][k]+arr[n][k-1]) % mod;
		}
	}
	
	cout << arr[N][K] << endl;

	return 0;

}