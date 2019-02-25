

class ThreeStacks(object):
    def __init__(self, stack_size):
        self.stack_size = stack_size
        self.arr = [None] * (stack_size * 3)
        self.head = [0, stack_size, stack_size*2]
        self.length = [0, 0, 0]

    def push(self, stack_num, data):
        stack_idx = stack_num-1
        if self.length[stack_idx] == self.stack_size:
            raise Exception("Stack %d is full" % stack_num)

        next_idx = self.head[stack_idx] + self.length[stack_idx]
        self.arr[next_idx] = data
        self.length[stack_idx] += 1

    def pop(self, stack_num):
        stack_idx = stack_num - 1
        if self.length[stack_idx] == 0:
            return None

        idx = self.head[stack_idx] + self.length[stack_idx] - 1
        ret = self.arr[idx]
        self.arr[idx] = None
        self.length[stack_idx] -= 1
        return ret


if __name__ == "__main__":
    stacks = ThreeStacks(4)
    stacks.push(1, 3)
    stacks.push(1, 4)
    stacks.push(1, 5)
    stacks.push(1, 6)
    
    stacks.push(2, 1)
    stacks.push(2, 2)
    stacks.push(2, 3)
    stacks.push(2, 4)

    stacks.push(3, 10)
    stacks.push(3, 20)
    stacks.push(3, 30)
    stacks.push(3, 40)

    assert(stacks.pop(1) == 6)
    assert(stacks.pop(1) == 5)
    assert(stacks.pop(1) == 4)
    assert(stacks.pop(1) == 3)
    assert(stacks.pop(1) == None)

    assert(stacks.pop(2) == 4)
    assert(stacks.pop(2) == 3)
    assert(stacks.pop(2) == 2)
    assert(stacks.pop(2) == 1)
    assert(stacks.pop(2) == None)

    assert(stacks.pop(3) == 40)
    assert(stacks.pop(3) == 30)
    assert(stacks.pop(3) == 20)
    assert(stacks.pop(3) == 10)
    assert(stacks.pop(3) == None)
