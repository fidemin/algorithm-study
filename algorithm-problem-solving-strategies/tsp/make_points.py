
import random
import datetime
import math
import sys

random.seed(datetime.datetime.now())
MAX_POS = 10

def make_point():
    x = random.randrange(MAX_POS+1)
    y = random.randrange(MAX_POS+1)
    return (x, y)

def make_points(n):
    return tuple(make_point() for _ in range(n))


def dist(point1, point2):
    return math.sqrt((point2[0] - point1[0])**2 + (point2[1] - point1[1])**2)

if __name__ == "__main__":
    if len(sys.argv) == 2:
        n = int(sys.argv[1])
    else:
        n = 8

    print(n)
    duplicate = True
    while duplicate:
        points = set(make_points(n))
        if len(points) == n:
            duplicate = False

    points = list(points)

    for i in range(n):
        for j in range(i+1, n):
            print("%d %d %.2f" % (i, j, dist(points[i], points[j])))
