
def is_permutation(s1, s2):
    if len(s1) != len(s2):
        return False

    counter = {} 
    for c in s1:
        counter[c] = counter.get(c, 0) + 1

    for c in s2:
        count = counter.get(c, 0)

        if count == 0:
            return False

        counter[c] = count - 1

    return True
