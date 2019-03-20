
visited = 0

def dfs(graph, start):
    global visited
    visited |= 1 << start
    for next_ in graph[start]:
        if not (visited & (1 << next_)):
            dfs(graph, next_)

def path_exist(graph, a, b):
    global visited
    visited = 0
    dfs(graph, a)
    if visited & (1 << b):
        return True

    visited = 0
    dfs(graph, b)
    if visited & (1 << a):
        return True

    return False


if __name__ == "__main__":
    graph = {
        1: [2, 3],
        2: [1, 3],
        3: [2],
        4: [5],
        5: [4],
    }

    assert(True == path_exist(graph, 1, 3))
    assert(True == path_exist(graph, 3, 1))
    assert(False == path_exist(graph, 1, 4))
    assert(False == path_exist(graph, 4, 1))
