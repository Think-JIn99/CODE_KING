//��ǥ ����
//��ǥ ����: �ش� ��ǥ�� ���� �� ������ ���� ��ǥ������ ������ ��ü
//���� ���� �ȵǼ� ���� ã�ƺ�

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, x;
vector<int> v, back;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
		back.push_back(x);
	}

	//�ߺ� ���� ����
	sort(v.begin(), v.end());//������������ ����
	v.erase(unique(v.begin(), v.end()), v.end());
	//unique: �ߺ����� �� �ڷ� �����Ⱚ���� ����, ������ vector�� �����Ⱚ�� ù��° ��ġ�� ��ȯ�Ǿ�
	//erase: ��ȯ�� �ּҺ��� �� �� ������ ����
	//�̷��� �Ǹ� ��� �ߺ� ���Ҹ� ������ �� �ִ�.
	//https://codingwell.tistory.com/26

	for (int i = 0; i < N; i++) {
		int result;
		result=lower_bound(v.begin(), v.end(), back[i]) - v.begin();

		cout << result << ' ';
	}

	return 0;
}