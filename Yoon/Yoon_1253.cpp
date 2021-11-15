#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

//�ش� ���ڸ� ������ �ٸ� ������ ������ �ش� ���ڸ� ǥ���� �� �ִ� ����

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	int cnt=0;
	int A[2001] = { 0, };

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A + N);

	for (int i = 0; i < N; i++) {
		int ans = A[i];
		int L = 0;
		int R = N - 1;
		
		//�������� �˰��� Ȱ��
		while (L < R) {
			if (A[L] + A[R] == ans) {
				if (L != i && R != i) { //L�� R�� �ٸ��� check
					cnt++;
					break;
				}
				else if (L == i) {
					L++;
				}
				else if (R == i) {
					R--;
				}
			}
			else if (A[L] + A[R] < ans) {
				L++; 
			}
			else {
				R--;
			}
			
		}
	}
	cout << cnt;
	return 0;
}

//�Ұ�: Ʈ���� �� ���� ������ �����ϴ°� �������� �˰����� ¥�µ� ������� �־���.
// �������� �˰���  https://butter-shower.tistory.com/226
//���� https://coding-insider.tistory.com/entry/%EB%B0%B1%EC%A4%80-1253-%EC%A2%8B%EB%8B%A4-CC
