//1043. ������
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, M;//N=�����, M=��Ƽ��
	int num;// ����� ��
	int Tn;//������ �ƴ� ����� ��ȣ
	int t[51] = { 0 };//������ �ƴ� ����� ��ȣ�� 1�� ǥ��
	int mn[51][51] = { 0 };//[�� ��Ƽ���� ���� ����Ǽ�][��ȣ]
	int arr_index[50] = { 0 };
	int val[50] = { 0 }; //�������� ����
	int result = 0;
	
	cin >> N >> M;
	cin >> num; //������ �ƴ� ����� ��
	for (int i = 0; i < num; i++) {
		cin >> Tn;
		t[Tn] = 1;
	}
	for (int i = 0; i < M; i++) {
		cin >> num; //��Ƽ���� ���� ����� ��
		arr_index[i] = num; //��Ƽ���� ���� ����� �� �迭�� ����
		for (int j = 0; j < num; j++) {
			cin >> mn[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < arr_index[i]; j++) {
			int v = mn[i][j];
			if (t[v] == 1) {//������ �˰� �ִٸ�
				val[i] = 1; //�������� �� �� ����.

				bool ans = true;
				for (int k = 0; k < arr_index[i]; k++) {
					if (t[mn[i][k]] == 0 && j != k) { 
						//i��° ��Ƽ�� j�� ������ �˰��ִµ� k�� �𸣰� j�� k�� ��ȣ�� �ٸ���
						//k�� ������ �˰� �ִٴ� ������
						ans = false;
						t[mn[i][k]] = 1; //k���� ����� ������ �˰� ������ ǥ��
					}
				}
				if (ans == false) { //ó�� ��Ƽ���� Ȯ��
					i = -1;
					break;
				}
			}
		}
	}
	for (int i = 0; i < M; i++) {
		if (val[i] == 0) { //�������� �� �� �ִٸ�
			result++;
		}
	}
	cout << result << endl;
	return 0;

}