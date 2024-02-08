

def find_left_most_position(nums, target):
    # nums are sorted in non-increasing order

    left = 0
    right = len(nums) - 1
    ret = -1

    while left <= right:
        mid = (left + right) // 2
        val = nums[mid]

        if target == val:
            ret = mid
            # continue until to find left most position
            right = mid - 1
        elif target < val:
            right = mid - 1
        else:
            left = mid + 1

    return ret
