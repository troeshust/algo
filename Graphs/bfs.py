from collections import deque


def bfs(g, root, visited):
    q = deque([root])
    while q:
        v = q.popleft()
        for to in g[v]:
            if not visited[to]:
                visited[to] = True
                q.append(to)
