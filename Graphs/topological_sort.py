def topological_sort(v):
    # topological order all of the children in the graph
    topo = []
    visited = set()
    dfs_stack = [(v, False)]  # (v, is_processed)

    while dfs_stack:
        v, processed = dfs_stack.pop()
        if processed:
            topo.append(v)
            continue
        if v not in visited:
            visited.add(v)
            dfs_stack.append((v, True))
            for child in v._children:
                dfs_stack.append((child, False))
    
    return reversed(topo)