//���� ��ġ��3
//������ ���� ����.
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 

	int T; //�׽�Ʈ ������ ����
	int K; //�Ҽ��� �����ϴ� ���� ��
	int k; //������ ����� ������ ���� ũ��
	long long ans = 0;


	cin >> T;
	
	//for (int i = 0; i < T; i++) {
	while(T--){
		cin >> K;
		priority_queue<long long, vector<long long>, greater<long long>> pq;

		//for (int j = 0; j < K; j++) {
		while(K--){
			cin >> k;
			pq.push(k);	//�켱���� ť�� ����
			//�ֳ��ϸ� ���� �͵���� ���ϰ� �״��� �����Ͱ� ���ϱ� ���ؼ���
			//�켱���� ť�� �־ ���� ���ڵ��� ���� ���� ����� �ٽ� �ִ´�.
		}
		
		ans = 0;

		while (!pq.empty()) {
			if (pq.size() == 1) break;

			long long first = pq.top();
			pq.pop(); //���� ���� ����
			long long second = pq.top();
			pq.pop(); //�״��� ���� ����

			ans += first + second; 
			pq.push(first + second); //���� ���ؼ� �켱���� ť�� ����
		}
		pq.pop();
		cout << ans << "\n";
	}
	return 0;
}