
from collections import deque

def bfs(adj, begin):

    discovered = [False] * len(adj)
    distance = [-1] * len(adj)
    spanning_tree = [-1]*len(adj) # save parent id 
    result = []
    queue = deque([begin])
    distance[begin] = 0 

    while len(queue):
        here = queue.popleft()
        result.append(here)
        for there in adj[here]:
            if not discovered[there]:
                distance[there] = distance[here] + 1
                discovered[there] = True
                spanning_tree[there] = here
                queue.append(there)

    return result, distance, spanning_tree

def shortest_path(spanning_tree, end):
    i = end

    path = []
    while i >= 0:
        path.append(i)
        i = spanning_tree[i]

    path.reverse()
    return path



if __name__ == "__main__":
    adj = []
    size = 6

    for _ in range(0, size):
        adj.append([])

    adj[0].append(1)
    adj[0].append(3)
    adj[1].append(2)
    adj[1].append(3)
    adj[3].append(1)
    adj[3].append(4)
    adj[4].append(2)
    adj[5].append(3)

    result, distance, spanning_tree = bfs(adj, 0)
    print(result)
    print(shortest_path(spanning_tree, 4))
    
