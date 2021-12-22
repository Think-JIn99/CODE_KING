#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
string site, password;
vector<pair<string, string>> list;

int search(int l, int r, string a) {
	int mid = (l + r) / 2;  //�������� �߾����� ��´�.
	if (list[mid].first == a) return mid;

	//return list[mid].first >= a ? search(l, mid, a) : search(mid + 1, r, a);

	if (list[mid].first >=a){
	    return search(l, mid, a);
	}
	else
	    return search(mid+1, r, a);

	//�̰Ŵ� ���� �ƴ°ɷ� �ٲٰ������
	//list�� ������������ ���ĵǾ������ϱ�
	//�߾ӿ� ��ġ�� site���� ������ ����, ũ�� ������ ã�´�.
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//cout, cin�� ������ ������ ������ִ� ����

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> site >> password;
		list.push_back({ site, password });
	}
	sort(list.begin(), list.end());
	//list�� ������������ ��������.
	//���ϱ�?

	for (int i = 0; i < m; i++) {
		cin >> site;
		int x = search(0, n - 1, site);
		//search �Լ��� ���� listó������ ������ �Է¹��� site�� ����Ǿ��ִ� site ��
		cout << list[x].second << '\n';
		//list�� password�� ���
	}
}

//�Ұ�: c++�� �ͼ������� �Ҹ��� ��������. ����� �ʾҴ�.
