
from random import randint
from collections import deque, namedtuple


NodePair = namedtuple('NodePair', ('first', 'second'))


class Node(object):
    def __init__(self, key, priority=None):
        if priority:
            self.priority = priority
        else:
            self.priority = randint(0, 100)
        self.key = key
        self.size = 1
        self.left = None
        self.right = None

    def __repr__(self):
        return "%d(%d)" % (self.key, self.priority)

    def set_left(self, node):
        self.left = node
        self._calc_size()


    def set_right(self, node):
        self.right = node
        self._calc_size()


    def _calc_size(self):
        self.size = 1 # 항상 새로 계산

        if self.left is not None:
            self.size += self.left.size

        if self.right is not None:
            self.size += self.right.size


def split(root, key):
    '''
    root를 루트로 하는 트립을 키 미만의 값과 이상의 값을
    갖는 두개의 트립으로 분리한다.
    '''
    if root is None:
        return NodePair(None, None)

    if root.key < key:
        rs = split(root.right, key)
        root.set_right(rs.first)
        return NodePair(root, rs.second)

    ls = split(root.left, key)
    root.set_left(ls.second)
    return NodePair(ls.first, root)


def insert(root, node):
    if root is None:
        return node

    if root.priority < node.priority:
        splitted = split(root, node.key)
        print(splitted)
        node.set_left(splitted.first)
        node.set_right(splitted.second)
        return node

    else:
        if node.key < root.key:
            root.set_left(insert(root.left, node))
        else:
            root.set_right(insert(root.right, node))

        return root


def merge(left, right):
    if left is None:
        return right
    if right is None:
        return left

    if left.priority > right.priority:
        left.set_right(merge(left.right, right))
        return left

    right.set_left(merge(left, right.left))
    return right


def erase(root, key):
    if root is None:
        return root

    if root.key == key:
        ret = merge(root.left, root.right)
        del root
        return ret

    if key < root.key:
        root.set_left(erase(root.left, key))
    else:
        root.set_right(erase(root.right, key))

    return root


def print_node(node):
    if node:
        print("%d(%d)" % (node.key, node.priority), end=" ")
    else:
        print("None", end=" ")


def print_by_layer(root):
    '''
    층별로 인쇄한다.
    '''

    if root is None:
        print(root)

    q = deque()
    q.appendleft((root, 0))
    current_layer = -1
    print_node(root)

    while len(q):
        node_pair = q.pop()
        node = node_pair[0]
        layer = node_pair[1]

        if layer > current_layer:
            print("")
            current_layer = layer

        if node.left:
            q.appendleft((node.left, current_layer+1))

        print_node(node.left)

        if node.right:
            q.appendleft((node.right, current_layer+1))

        print_node(node.right)


def print_preorder(root):
    print_node(root)

    if root.left:
        print_preorder(root.left)

    if root.right:
        print_preorder(root.right)


def kth(root, k):
    if root is None:
        return None

    l_size = 0

    if root.left is not None:
        l_size = root.left.size

    if k <= l_size:
        return kth(root.left, k)
    elif k == l_size + 1:
        return root
    return kth(root.right, k - l_size - 1)


def count_less_than(root, key):
    if root is None:
        return 0

    if root.key >= key:
        return count_less_than(root.left, key)

    ls = root.left.size if root.left else 0

    return ls + 1 + count_less_than(root.right, key)


if __name__ == "__main__":
    root = Node(5)
    root = insert(root, Node(3))
    root = insert(root, Node(7))
    root = insert(root, Node(4))
    root = insert(root, Node(10))
    root = insert(root, Node(12))
    #print_by_layer(root)
    #print("\n------\n")
    #root = erase(root, 3)
    #print_by_layer(root)
    #print_preorder(root)

    print(kth(root, 4))
    print(count_less_than(root, 6))
