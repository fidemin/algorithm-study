
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


def unique_subsets(nums):
    ret = {()}
    for num in nums:
        this_set = [tuple(sorted(list(s)+[num])) for s in ret]
        for s in this_set:
            ret.add(s)

    return [list(s) for s in ret]


def subset_with_target_sum(nums, target):
    subset = {()}
    ret = set()
    for num in nums:
        this_set = []
        for s in subset:
            new_set = tuple(sorted(list(s) + [num]))
            this_set.append(new_set)
            if sum(new_set) == target:
                ret.add(new_set)

        for s in this_set:
            subset.add(s)

    return [list(s) for s in ret]







