//1918.���� ǥ���
//���� ǥ���: �����ڸ� �ǿ����� �ڿ� ���� ���
//https://woongsios.tistory.com/288
//������ �켱����: '(', ')' > '*' , '/' > '+' , '-'
//������ ���Լ���
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string input;
	string result;
	stack <char> op;

	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if ('A' <= input[i] && 'Z' >= input[i]) {
			result += input[i];
			continue;
		}
		//�ǿ����ڵ��� result�� ����

		if (input[i] == '(') {
			op.push(input[i]);
			continue;
		}
		//'('�� ��� ���ÿ� �߰�

		if (input[i] == ')') {
			while (op.top() != '(') {
				result += op.top();
				op.pop();
			}
			op.pop();
			continue;
		}
		//')'�� ��� '('�� ���ö����� result�� ������ pop

		if (input[i] == '*' || input[i] == '/') {
			while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
				result += op.top();
				op.pop();
			}
		}
		//'*'�� '/'���� ���� �켱������ �����ڴ� ���� ������ 
		//'*'�Ǵ� '/'�� top�϶� result�� �߰�

		else {
			while (!op.empty() && op.top() != '(') {
				result += op.top();
				op.pop();
			}
		}
		//'+', '-'�� ��� ������ �����ڵ��� �ڽź��� �켱������ ���ų� �����Ƿ� 
		//'('�� ���ö����� result �� �߰�
		op.push(input[i]);
		

	}
	while (!op.empty()) {
		result += op.top(); //���� ������ result�� �߰�
		op.pop();
	}
	cout << result << "\n";
	return 0;

}