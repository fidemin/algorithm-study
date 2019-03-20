
class Node(object):
    def __init__(self, data):
        self.next = None
        self.data = data


def find_reverse_kth(head, k):
    if not head:
        return None

    count = 0
    reverse_kth = None
    current = head


    # count가 k가 되었을 때, head를 시작으로 추적하면 된다.
    while current:
        current = current.next
        count += 1
        if count == k:
            reverse_kth = head
        elif reverse_kth:
            reverse_kth = reverse_kth.next


    if count < k:
        return None

    return reverse_kth.data


def find_reverse_kth_best(head, k):
    # 원래 답. 위 함수와 시간 복잡도와 공간 복잡도는 똑같다.
    # 원리도 똑같다. 여기서는 두개의 노드를 사용해 추적한다.
 
    p1 = head
    p2 = head

    for i in range(k):
        if not p1:
            return None # out of bound
        p1 = p1.next

    while p1:
        p1 = p1.next
        p2 = p2.next

    return p2.data


if __name__ == "__main__":
    head = None
    current = head

    for data in [4, 10, 2, 4, 5, 3, 2]:
        if not head:
            head = Node(data)
            current = head
        else:
            current.next = Node(data)
            current = current.next

    assert(find_reverse_kth(head, 1) == 2)
    assert(find_reverse_kth(head, 2) == 3)
    assert(find_reverse_kth(head, 6) == 10)
    assert(find_reverse_kth(head, 7) == 4)


    assert(find_reverse_kth_best(head, 1) == 2)
    assert(find_reverse_kth_best(head, 2) == 3)
    assert(find_reverse_kth_best(head, 6) == 10)
    assert(find_reverse_kth_best(head, 7) == 4)
