
from collections import deque

def sort_stack(stack):
    stack2 = deque()

    while stack:
        if not stack2:
            stack2.appendleft(stack.popleft())
            continue

        this = stack.popleft()

        if this < stack2[0]:
            tmp = stack2.popleft()
            stack2.appendleft(this)
            stack2.appendleft(tmp)
        else:
            stack2.appendleft(this)


    while stack2:
        stack.appendleft(stack2.popleft())

if __name__ == "__main__":
    stack = deque()
    stack.appendleft(3)
    stack.appendleft(4)
    stack.appendleft(1)
    stack.appendleft(2)
    sort_stack(stack)
    print(stack)
