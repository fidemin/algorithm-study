def solve_one(row):
    left = 0
    left_value = row[0]
    left_count = 0

    while left < len(row):
        if row[left] == left_value:
            left += 1
            left_count += 1
        else:
            left -= 1
            break

    right = len(row) - 1
    right_value = row[-1]
    right_count = 0

    while left < right:
        if row[right] == right_value:
            right -= 1
            right_count += 1
        else:
            right += 1
            break

    if left_value == right_value:
        return len(row) - (left_count + right_count)

    return len(row) - max(left_count, right_count)


def solve():
    num_of_questions = int(input())

    for _ in range(num_of_questions):
        input()

        row = [int(s) for s in input().split(' ')]
        print(solve_one(row))


if __name__ == '__main__':
    solve()
