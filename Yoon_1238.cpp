//1238. ��Ƽ - ���ͽ�Ʈ��
//N���� �л����� x�� ������ ���ٰ� �ٽ� �ڽŵ��� ���� ������ ���ƿ��µ�
//���� �����ɸ��� �л��� �ҿ�ð�
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int N, M, X; //�л���, ���μ�, 
int a, b, c; //������, ����, �ҿ�ð�
vector<pair<int, int>> map[1001];
int dist[1010];
int res[1010];

void dijkstra(int start) {

	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push(make_pair(0, start)); //����ġ, ��������

	while (pq.empty() == 0) {
		int current = pq.top().second;
		int cost = -pq.top().first; //-�� �־ �������� �־� �ּҰ��� ���� �������� �� ->�ַ�� ��..

		pq.pop();

		if (dist[current] < cost) continue;

		for (int i = 0; i < map[current].size(); i++) {

			int next = map[current][i].first; //���� ��� u�϶� ������ v�� ���� ���
			int ncost = map[current][i].second;

			if (ncost + cost < dist[next]) { //���� ����ġ�� ���� ����ġ�� ���� ���� ����� ����ġ���� ������
				dist[next] = ncost + cost; //���� ����� ����ġ�� ������ 
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//input
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		map[a].push_back(make_pair(b, c));
	}
	
	//dijkstra ����~
	for (int i = 1; i <= N; i++) {//��� �л����� x�� ������ ���µ� �ɸ��� �ִ� �ҿ�ð� 
		for (int j = 1; j <= N; j++) dist[j] = INF;
		dijkstra(i);
		res[i] = dist[X]; //���� �ð� ����
	}

	for (int j = 1; j <= N; j++) dist[j] = INF; 
	dijkstra(X);//x�� �������� �ڽ� ������ ���� �ִ� �ҿ�ð�

	//�ι� �ϴ� ������ �ܹ����̱� ������ ���ٰ� ���� �ð��� ���� ������ ����.
	//��� �ַ�Ǻ��� �˾���.....

	int result = 0;
	for (int i = 1; i <= N; i++) {
		res[i] += dist[i]; //���½ð��� ���½ð� ���ؼ� ����
		result = max(result, res[i]); //���� ū �� ���

	}

	cout << result;
	
}