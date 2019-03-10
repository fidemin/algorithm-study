
def swap(arr, i, j):
    tmp = arr[j]
    arr[j] = arr[i]
    arr[i] = tmp


def partition(arr, left, right):
    original_right = right
    pivot = arr[original_right]
    right -= 1

    while left <= right:
        while left < original_right and arr[left] <= pivot:
            left += 1

        while right > 0 and arr[right] > pivot:
            right -= 1

        if left <= right:
            swap(arr, left, right)
            left += 1
            right -= 1

    swap(arr, left, original_right) 
    return left


def quick_sort(arr, left, right):
    idx = partition(arr, left, right)

    if idx - 1 > left:
        quick_sort(arr, left, idx - 1)

    if idx + 1 < right:
        quick_sort(arr, idx + 1, right)


if __name__ == "__main__":
    arr = [1, 3, 2, 2, 2, 2, 5, 12, 3, 4]

    quick_sort(arr, 0, len(arr)-1)
    print(arr)

