
class DisjointSet(object):
    def __init__(self, size):
        self.parent = []
        self.rank = []
        for i in range(size):
            self.parent.append(i)
            self.rank.append(1)

    def find(self, u):
        if u == self.parent[u]:
            return u
        self.parent[u] = self.find(self.parent[u])
        return self.parent[u]

    def union(self, u, v):
        u = self.find(u)
        v = self.find(v)
        if (u == v) return 
        if rank[u] > rank[v]:
            self.parent[v] = u
        else:
            self.parent[u] = v

        if rank[u] == rank[v]:
            rank[v] += 1


if __name__ == "__main__":
    ds = DisjointSet(10)

    ds.union(1, 9)
    ds.union(0, 8)
    ds.union(8, 9)
    print(ds.find(0))
    print(ds.parent)
