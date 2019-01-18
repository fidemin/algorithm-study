# -*- coding: utf-8 -*-

def min_count(n):
    min_list = [0,0]

    i = 2

    while i <= n:
        values = []
        if i % 3 == 0:
            tmp = i
            divide = 0
            while tmp % 3 == 0:
                tmp = tmp / 3
                divide += 1

            value = divide + min_list[int(i/(3**divide))]
            values.append(value)

        if i % 2 == 0:
            value = 1 + min_list[int(i/2)]
            values.append(value)

        value = 1 + min_list[int(i-1)]
        values.append(value)
        min_list.append(min(values))

        #print("i:", i, "values:", values)

        i = i + 1

    return min_list[n]

if __name__ == "__main__":
    n = int(input())
    print(min_count(n))
