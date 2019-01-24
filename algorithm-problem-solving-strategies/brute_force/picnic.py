
def make_is_friend(friends):
    is_friend = [[False]* 10 for _ in range(10)]
    is_friend[0][0] = True

    for i in range(0, len(friends), 2):
        is_friend[friends[i]][friends[i+1]] = True
        is_friend[friends[i+1]][friends[i]] = True

    return is_friend


def count_pairings_recursive(n, is_friend, taken):
    first_free = None
    for i in range(n):
        if not taken[i]:
            first_free = i
            break;

    if first_free is None:
        return 1

    result = 0
    for i in range(first_free+1, n):
        if not taken[i] and is_friend[first_free][i]:
            taken[first_free] = taken[i] = True
            result += count_pairings_recursive(n, is_friend, taken)
            taken[first_free] = taken[i] = False
    return result

def count_pairings(n, friends):
    is_friend = make_is_friend(friends)
    taken = [False] * 10

    result = count_pairings_recursive(n, is_friend, taken, 0)
    return result


if __name__ == "__main__":
    print(count_pairings(4, (0, 1, 1, 2, 2, 3, 3, 0, 0, 2, 1, 3)))
    print(count_pairings(6, (0, 1, 0, 2, 1, 2, 1, 3, 1, 4, 2, 3, 2, 4, 3, 4, 3, 5, 4, 5)))

    
