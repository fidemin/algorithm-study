import sys

MAX = 20
n = MAX

INF = 987654321

dist = [[0] * MAX for _ in range(MAX)]
# MAX by (1<<MAX) 행렬임에 주의하자 (반대로 생각하기 쉽다)
cache = [[-1] * (1<<MAX) for _ in range(MAX)]
# 각 점에서 가장 가까운 점의 거리를 저장한다
min_edge = [INF] * MAX

best = INF

# 완전 탐색
def shortest_path(path, visited, current_length):
    if len(path) == n:
        return current_length + dist[path[len(path)-1]][0]

    ret = INF
    for next_ in range(n):
        here = path[len(path)-1]
        if not visited & (1 << next_):
            path.append(next_)
            ret = min(ret, shortest_path(path, visited + (1 << next_), current_length + dist[here][next_]))
            del path[len(path) -1]

    return ret


# 동적 계획법
def shortest_path2(here, visited):
    if visited == ((1 << n) - 1):
        return dist[here][0]

    ret = cache[here][visited]
    if ret >= 0:
        return ret

    ret = INF

    for next_ in range(n):
        if visited & (1<<next_):
            continue

        cand = shortest_path2(next_, visited + (1<<next_)) + dist[here][next_]
        ret = min(ret, cand)

    cache[here][visited] = ret
    return ret


def simple_heuristic(visited):
    # 앞으로 방문할 모든 점에서의 거리의 최소 값을 모두 더한다.
    ret = min_edge[0]
    for i in range(n):
        if visited & (1<<i) != 0:
            ret += min_edge[i]

    return ret


# 조합 탐색
def search(path, visited, current_length, simple_h=False):
    global best
    # 이미 베스트 보다 커졌다면 중지한다.
    if simple_h:
        if best <= (current_length + simple_heuristic(visited)):
            return
    else:
        if best <= current_length:
            return

    if len(path) == n:
        best = min(best, current_length + dist[path[len(path)-1]][0])
        return

    for next_ in range(n):
        if visited & (1<<next_) != 0:
            continue

        here = path[len(path)-1]
        path.append(next_)
        search(path, visited + (1<<next_), current_length + dist[here][next_], simple_h=simple_h)
        del path[len(path)-1]

    return

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        for j in range(i+1, n):
            row = input().split(" ")
            here = int(row[0])
            there = int(row[1])
            distance = float(row[2])
            dist[here][there] = distance
            dist[there][here] = distance

    for i in range(n):
        for j in range(n):
            if i != j:
                min_edge[i] = min(min_edge[i], dist[i][j])

    print(min_edge)

    import time
    '''
    ret = 0
    visited = 1 # 0번 지점은 방문했음
    start = time.time()
    ret = shortest_path([0], visited, 0)
    end = time.time()
    print("brute force")
    print(" ", ret)
    print("  exec time (s):", end - start)
    '''

    ret = 0
    visited = 1 # 0번 지점은 방문했음
    start = time.time()
    ret = shortest_path2(0, visited)
    end = time.time()
    print("dynamic programming")
    print(" ", ret)
    print("  exec time (s):", end - start)

    ret = 0
    visited = 1 # 0번 지점은 방문했음
    best = INF
    start = time.time()
    ret = search([0], visited, 0)
    end = time.time()
    print("combinational search")
    print(" ", best)
    print("  exec time (s):", end - start)


    ret = 0
    visited = 1 # 0번 지점은 방문했음
    best = INF
    start = time.time()
    ret = search([0], visited, 0, simple_h=True)
    end = time.time()
    print("combinational search: simple heuristic")
    print(" ", best)
    print("  exec time (s):", end - start)
