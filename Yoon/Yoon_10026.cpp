#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 100
//������ �����¿�� ������ �ִ� ��찡 ���� ����.
//���� ���� ó�� R�� ���� ����, ���� B�� ���� ����.
//G�� ���� ����, R�� ��������-> �� 4
//G�� ��� R�̶�� �ϸ�
//�߰��� �ִ� B�� �����ϰ� R-B-R������� BFS ->�� 3

int N;
char map[MAX][MAX];
int visit[MAX][MAX];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void bfs(int a, int b) {

	queue < pair<int, int >> q;
	q.push(make_pair(a, b));
	visit[a][b] = true;

	while (q.empty() == 0) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
            //�����¿� �湮
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (visit[nx][ny] == false) {
					if (map[nx][ny] == map[x][y]) {
						visit[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

    //�Է�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

    int Answer, Answer2; //ó��, ���ϻ����� ���

    Answer = Answer2 = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visit[i][j] == false)
            {
                bfs(i, j);
                Answer++;
                //cout << i << j << '\n';

            }
        }
    }

    //���ϻ����� ��� �ʷϻ��� �������� ������ �� �����Ƿ� G�� R�� �ٲ�
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){

            if (map[i][j] == 'G') map[i][j] = 'R';
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){

            if (visit[i][j] == false)
            {
                bfs(i, j);
                Answer2++;
               // cout << i << j << '\n';
            }
        }
    }

    cout << Answer << " " << Answer2 << endl;



	return 0;
}

// ����  https://yabmoons.tistory.com/55 