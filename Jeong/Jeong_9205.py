import sys
from collections import deque
input = sys.stdin.readline
t = int(input())
def bfs(graph):
    visited = [False for _ in range(n + 2)]
    queue = deque([0]) #0번 인덱스는 출발점이다,
    visited[0] = True
    while queue:
        cur = queue.pop()
        if cur == n - 1: return 'happy'
        for i,(x,y) in enumerate(graph):
            if not visited[i]:
                if abs(graph[cur][0] - x) + abs(graph[cur][1] - y) <= 1000: #거리가 1000이하 인지 확인한다.
                    queue.append(i) #연결돼 있다는 의미이므로 큐에 추가해준다.
                    visited[i] = True
    return 'sad'

for _ in range(t):
    n = int(input()) + 2
    graph = [tuple(map(int,input().split())) for _ in range(n)]
    print(bfs(graph))
  

