
class Node(object):
    def __init__(self, data):
        self.next = None
        self.data = data


def delete_dups(node):
    if not node:
        return node

    if not node.next:
        return node

    count = {node.data: True}

    current = node

    while current.next:
        if count.get(current.next.data, False):
            current.next = current.next.next
        else:
            count[current.next.data] = True
            current = current.next

    return node


if __name__ == "__main__":
    head = None
    current = head

    for data in [4, 4, 2, 4, 5, 3, 2]:
        if not head:
            head = Node(data)
            current = head
        else:
            current.next = Node(data)
            current = current.next

 
    head = delete_dups(head)
    
    current = head

    while current is not None:
        print(current.data)
        current = current.next
