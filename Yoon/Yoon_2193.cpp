//2193. ��ģ��
#include <iostream>
using namespace std;

long long DP[100][2]; //DP[�ڸ���][������ ����] 
long long result;
//�� int�� �ƴ϶� longlong �ϱ� -> DPũ�⸦ ����ؼ� longlong Ÿ������ ����������Ѵ�
// ��� Ʋ�ȴٱ淡 ã�ƺ��ϱ� �׷��ٳ�...

int main() {
	int N;
	cin >> N;

	DP[1][0] = 0; //���ڸ��ε� 0���� ������ ��ģ�� ����
	DP[1][1] = 1; //���ڸ��ε� 1�� ������ ��ģ�� 1��

	for (int i = 2; i <= N; i++) {
		DP[i][0] = DP[i - 1][0] + DP[i - 1][1]; //0���� ������ �տ� 0�̵� 1�̵� ���x
		DP[i][1] = DP[i - 1][0]; //1�� ������ �տ� 0���� ��������
	}
	result = DP[N][0] + DP[N][1]; //0���� ������ ��ģ�� ���� + 1�� ������ ��ģ�� ����
	
	cout << result << endl;
	return 0;
}