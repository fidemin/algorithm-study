
def all_subsets(nums):
    ret = [[]]

    for num in nums:
        this_set = [s + [num] for s in ret]
        ret.extend(this_set)

    return ret


def all_subset_sums(nums):
    ret = [0]

    for num in nums:
        this_set = [s + num for s in ret]
        ret.extend(this_set)

    return ret
