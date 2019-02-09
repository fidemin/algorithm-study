
import heapq

h = []
heapq.heappush(h, (3, "Go to home"))
heapq.heappush(h, (10, "Do not study"))
heapq.heappush(h, (1, "Enjoy!"))
heapq.heappush(h, (4, "Eat!"))
heapq.heappush(h, (7, "Pray!"))

print(h)


first = heapq.heappop(h)
second = heapq.heappop(h)
third = heapq.heappop(h)

print("first:", first)
print("second:", second)
print("third:", third)


h = [(3, "Go to home"), (10, "Do not study"), (1, "Enjoy!"), (4, "Eat!"), (7, "Pray!")]
heapq.heapify(h)
print(h)

max_h = [(-ele[0], ele[1]) for ele in h]
heapq.heapify(max_h)
print(max_h)
