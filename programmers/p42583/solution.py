
from collections import deque

class TruckOnBridge(object):
    def __init__(self, weight):
        self.weight = weight
        self.pos = 0


    def __repr__(self):
        return "Truck(weight=%d,pos=%d)" % (self.weight, self.pos)


def one_turn(trucks):
    for truck in trucks:
        truck.pos += 1


def solution(bridge_length, weight, truck_weights):
    truck_queue = deque(truck_weights)

    first_truck = TruckOnBridge(truck_queue.popleft())
    t_count = 1
    trucks_on_bridges = deque()
    trucks_on_bridges.appendleft(first_truck)
    weight_on_bridges = first_truck.weight

    while trucks_on_bridges:
        # 1초 마다 진행
        one_turn(trucks_on_bridges)
        if trucks_on_bridges[len(trucks_on_bridges)-1].pos == bridge_length:
            removed = trucks_on_bridges.pop()
            weight_on_bridges -= removed.weight


        if truck_queue and truck_queue[0] + weight_on_bridges <= weight:
            truck = TruckOnBridge(truck_queue.popleft())
            trucks_on_bridges.appendleft(truck)
            weight_on_bridges += truck.weight

        t_count += 1

    return t_count


if __name__ == "__main__":
    assert(8 == solution(2, 10, [7, 4, 5, 6]))
    assert(101 == solution(100, 100, [10]))
    assert(110 == solution(100, 100, [10,10,10,10,10,10,10,10,10,10]))
