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
