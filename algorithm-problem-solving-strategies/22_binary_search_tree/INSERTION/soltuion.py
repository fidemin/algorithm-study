
import heapq

def pop_kth(heap, k):
    i = 0
    tmp = []
    ret = None

    while i <= k:
        if i == k:
            ret = heapq.heappop(heap)
        else:
            tmp.append(heapq.heappop(heap))
        i += 1

    # 뺀 아이템을 다시 넣는다.
    for ele in tmp:
        heapq.heappush(heap, ele)

    return ret


def solve(n, arr):
    '''
    책 해설의 treap 대신 heap을 사용한다.
    '''
    heap = list(range(1, n+1))
    heapq.heapify(heap)

    ret = [0]*n

    for i in range(n-1, -1, -1):
        ret[i] = pop_kth(heap, i - arr[i])

    return ret


if __name__ == "__main__":
    m = int(input())

    for _ in range(m):
        n = int(input())
        arr = list(map(int, input().split()))
        print(" ".join(map(str, solve(n, arr))))

