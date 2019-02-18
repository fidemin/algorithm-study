
class Node(object):
    def __init__(self, value):
        self.value = value
        self.next = None


class Stack(object):
    def __init__(self):
        self.head = None

    def push(self, value):
        if self.head is None:
            self.head = Node(value)
        else:
            node = Node(value)
            node.next = self.head
            self.head = node

    def pop(self):
        if self.head is None:
            return None

        node = self.head
        self.head = node.next
        return node.value


if __name__ == "__main__":
    stack = Stack()
    stack.push(1)
    stack.push(2)
    stack.push(3)

    assert(stack.pop() == 3)
    assert(stack.pop() == 2)
    assert(stack.pop() == 1)
