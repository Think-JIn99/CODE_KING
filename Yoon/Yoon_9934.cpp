#include <iostream>
#include <vector>
using namespace std;

vector<int> height[11];
int arr[1024] = { 0, };
int k, node;

void getTree(int start, int end, int level) { //����Ʈ�� ����� �Լ�
	int mid = (start + end) / 2;
	height[level].push_back(arr[mid]);

	if (start == end) {
		return;
	}

	getTree(start, mid - 1, level + 1); //mid ����Ʈ��
	getTree(mid + 1, end, level + 1);  //mid ������ Ʈ��
}

int main() {
	cin >> k;
	int cnt = 1;
	for (int i = 0; i < k; i++) {
		cnt *= 2;
	}
	cnt -= 1;
	//cnt�� ��� ���� 2**k-1

	for (int i = 0; i < cnt; i++) {
		cin >> node;
		arr[i] = node;
	}
	//�Է��� �� �迭�� �ֱ�

	getTree(0, cnt - 1, 1);

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < height[i].size(); j++) {
			cout << height[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
