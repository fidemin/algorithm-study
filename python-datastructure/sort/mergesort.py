

def sort(nums: list[int]):
    if len(nums) in [0, 1]:
        return
    mergesort(nums, 0, len(nums)-1)


def mergesort(nums, left, right):
    if left == right:
        return

    mid = left + (right - left) // 2
    mergesort(nums, left, mid)
    mergesort(nums, mid+1, right)
    merge(nums, left, mid, right)


def merge(nums, left, mid, right):
    if left == right:
        return

    p0 = left
    p1 = mid + 1
    temp = []
    while p0 <= mid or p1 <= right:
        if p1 > right:
            temp.append(nums[p0])
            p0 += 1
            continue

        if p0 > mid:
            temp.append(nums[p1])
            p1 += 1
            continue

        if nums[p0] <= nums[p1]:
            temp.append(nums[p0])
            p0 += 1
        else:
            temp.append(nums[p1])
            p1 += 1

    nums[left: right+1] = temp
