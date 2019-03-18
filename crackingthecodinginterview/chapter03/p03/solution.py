
from collections import deque

class SetOfStacks(object):
    def __init__(self, height):
        self._height = height
        self._size = 0
        self._deques = deque()

    def push(self, data):
        if not self._deques or len(self._deques[0]) == self._height:
            self._deques.appendleft(deque())

        self._deques[0].appendleft(data)

    def pop(self):
        ret = self._deques[0].popleft()
        if len(self._deques[0]) == 0:
            self._deques.popleft()
        return ret


if __name__ == "__main__":
    stack = SetOfStacks(2)
    stack.push(2)
    stack.push(3)
    print(stack._deques)
    stack.push(4)
    stack.push(1)
    print(stack._deques)
    assert(stack.pop() == 1)
    assert(stack.pop() == 4)
    print(stack._deques)
    assert(stack.pop() == 3)
    assert(stack.pop() == 2)
    print(stack._deques)
