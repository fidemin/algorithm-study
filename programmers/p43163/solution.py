from collections import deque, namedtuple

Node = namedtuple('Node', ('idx', 'depth'))

cached = {}

def is_connected(s1, s2):
    n = len(s1)

    diff_count = 0
    for i in range(n):
        if s1[i] != s2[i]:
            diff_count += 1

        if diff_count > 1:
            return False

    return diff_count == 1


def solution(begin, target, words):
    if target not in words:
        return 0

    words.insert(0, begin)
    n = len(words)
    graph = [[] for _ in range(n)]

    for i in range(n):
        for j in range(i+1, n):
            if is_connected(words[i], words[j]):
                graph[i].append(j)
                graph[j].append(i)

    #BFS
    queue = deque([])
    queue.appendleft(Node(idx=0, depth=0))
    discovered = 1

    while(queue):
        node = queue.pop()

        if words[node.idx] == target:
            return node.depth

        depth = node.depth
        nexts = graph[node.idx]

        for next_idx in nexts:
            if not discovered & 1 << next_idx:
                discovered |= 1 << next_idx
                queue.appendleft(Node(idx=next_idx, depth=depth+1))

    return 0


if __name__ == "__main__":
    assert(is_connected("abc", "abb"))
    assert(not is_connected("abc", "acd"))

    assert(solution("hit", "cog", ["hot","dot","dog","lot","log","cog"]) == 4)
    assert(solution("hit", "cog", ["hot","kot","dog","lod","log","cog"]) == 0)
