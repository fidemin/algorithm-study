
from collections import deque

class Stack(object):
    def __init__(self):
        self._stack = deque()
        self._min = deque()

    def push(self, data):
        self._stack.appendleft(data)
        if not self._min:
            self._min.appendleft(data)
        else:
            self._min.appendleft(min(self._min[0], data))

    def pop(self):
        self._min.popleft()
        return self._stack.popleft()

    def min(self):
        if self._min:
            return self._min[0]
        else:
            return None


if __name__ == "__main__":
    stack = Stack()
    stack.push(5)
    assert(stack.min() == 5)
    stack.push(6)
    assert(stack.min() == 5)
    stack.push(1)
    assert(stack.min() == 1)
    stack.pop()
    assert(stack.min() == 5)
    stack.pop()
    assert(stack.min() == 5)
