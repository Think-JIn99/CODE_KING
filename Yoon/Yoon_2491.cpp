//2491. ����
#include <iostream>
#include <algorithm>
#define MAX 100010
using namespace std;

int arr[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int answer = 1;
	int len = 1;
	int N;

	cin >> N;
	//�Է¹ޱ�
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	len = 1;
	//���ڵ��� Ŀ����
	for (int i = 1; i < N; i++) {
		if (arr[i] <= arr[i - 1]) {
			len++;
		}
		else len = 1; //����� 1�� �ʱ�ȭ
		answer = max(answer, len);
	}
	len = 1;
	//���ڵ��� �۾�����
	for (int i = 1; i < N; i++) {
		if (arr[i] >= arr[i - 1]) {
			len++;
		}
		else len = 1; //����� 1�� �ʱ�ȭ
		answer = max(answer, len);
	}

	cout << answer ;
	return 0;
}
//������ �߸������ߴ��� 9���̳� Ʋ�ȴ�.