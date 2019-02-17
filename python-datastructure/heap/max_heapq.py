
import heapq

class ReverseLessThan(object):
    def __init__(self, value):
        self.value = value

    def __lt__(self, other):
        return self.value > other.value

    def __repr__(self):
        return str(self.value)


def heappush(heap, item):
    reverse_item = ReverseLessThan(item)
    heapq.heappush(heap, reverse_item)


def heappop(heap):
    reverse_item = heapq.heappop(heap)
    return reverse_item.value


def heapify(lst):
    for i, ele in enumerate(lst):
        lst[i] = ReverseLessThan(ele)
    heapq.heapify(lst)


if __name__ == "__main__":
    h = []
    heappush(h, (3, "Go to home"))
    heappush(h, (10, "Do not study"))
    heappush(h, (1, "Enjoy!"))
    heappush(h, (4, "Eat!"))
    heappush(h, (7, "Pray!"))
    heappush(h, (4, "Dup Eat!"))

    print(h)


    count = 1
    while h:
        print("%dth : %s" % (count, heappop(h)))
        count += 1

    lst = ["ab", "dh", "hihi", "kk1", "power"]
    heapify(lst)
    print(lst)
    count = 1
    while lst:
        print("%dth : %s" % (count, heappop(lst)))
        count += 1
