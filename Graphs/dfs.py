# Avoid recursion in python as much as you can
def dfs_stack(v, graph):
    global visited
    stack = [(v, 0)]  # Stack contains tuples of (node, current_depth)
    visited.add(v)
 
    while stack:
        node, cur_depth = stack.pop()
        
        for u in graph[node]:
            if u not in visited:
                visited.add(u)
                stack.append((u, cur_depth + 1))


# Base DFS, for example to check is there a way from vertex1 to vertex2
def dfs(v, g, used):
    used[v] = True
    for to in g[v]:
        if not used[to]:
            dfs(to, g, used)


# Find all vertices in current component
def dfs_comp(v, g, used, comp):
    used[v] = True
    comp.append(v)
    for to in g[v]:
        if not used[to]:
            dfs_comp(to, g, used, comp)


