from dfs import dfs_comp


def read_graph():
    g = {}
    n, m = [int(i) for i in input().split(' ')]
    for i in range(n):
        g[i] = []

    for i in range(m):
        v, to = [int(j) for j in input().split(' ')]
        v -= 1
        to -= 1
        g[v].append(to)
        g[to].append(v)
    return g, n, m


def compute_components(g, search=dfs_comp):
    n = len(g)
    used = [False] * n
    comps = []

    for i in range(n):
        if not used[i]:
            cur_comp = []
            search(i, g, used, cur_comp)
            comps.append(cur_comp)

    return comps


def print_components(comps):
    print(len(comps))
    for comp in comps:
        print(len(comp))
        for i in comp:
            print(i + 1, end=' ')
    print()
