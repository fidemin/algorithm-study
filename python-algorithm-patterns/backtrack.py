

def _permu_backtrack(current, left, ret):
    if len(left) == 0 and current:
        ret.append(current)

    for i in range(len(left)):
        next_c = current + [left[i]]
        _permu_backtrack(next_c, left[:i] + left[i+1:], ret)


def permutation(nums):
    ret = []
    _permu_backtrack([], nums, ret)
    return ret



