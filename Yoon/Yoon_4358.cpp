#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;

//vector<pair<string, double>> ans;
map<string, float> ans; //���� ������ ���ͷ� ������� �ߴµ� map���

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	string t;

	float cnt = 0;

//	for (int i = 0; i < max; i++) {
//		cin >> t;
//		tree.push_back(t);
//		cnt++;
//	}
	
	while (getline(cin, t)) {
		if (ans.find(t) == ans.end()) {
			ans[t] = 1;
		}
		else {
			++ans[t]; //�ش� ���� �׷� �� 1 ����
		}
		++cnt; //��ü ���� �� 1 ����
	}

	cout << fixed; 
	cout.precision(4); //�Ҽ��� �Ʒ� ��°�ڸ������� ǥ���ϵ��� ����

	for (auto it = ans.begin(); it != ans.end(); it++) { //�� ��ü ���� ���
		float val = (it->second / cnt) * 100;
		cout << it->first << ' ' ;
		cout << val << "\n";
	}
	
	return 0;
}