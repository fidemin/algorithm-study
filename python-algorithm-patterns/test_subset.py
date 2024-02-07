import pytest
from subset import all_subsets, all_subset_sums, unique_subsets, subset_with_target_sum


def _assert_subset(subset1, subset2):
    assert len(subset1) == len(subset2)
    subset1.sort()
    subset2.sort()
    [s.sort() for s in subset1]
    [s.sort() for s in subset2]

    for i in range(len(subset1)):
        s1 = subset1[i]
        s2 = subset2[i]

        assert len(s1) == len(s2)
        for j in range(len(s1)):
            assert s1[j] == s2[j]


@pytest.mark.parametrize('test_input,expected', [
    ([], [[]]),
    ([1], [[], [1]]),
    ([2, 5, 7], [[], [2], [5], [2, 5], [7], [2, 7], [5, 7], [2, 5, 7]]),
    ([1, 2, 3, 4], [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3], [4], [1, 4], [2, 4], [1, 2, 4], [3, 4],
                    [1, 3, 4], [2, 3, 4], [1, 2, 3, 4]])
])
def test_all_subsets(test_input, expected):
    actual = all_subsets(test_input)
    _assert_subset(actual, expected)


@pytest.mark.parametrize('test_input,expected', [
    ([], [0]),
    ([1], [0, 1]),
    ([2, 5, 7], [0, 2, 5, 7, 7, 9, 12, 14]),
    ([1, 2, 3, 4], [0, 1, 2, 3, 3, 4, 5, 6, 4, 5, 6, 7, 7, 8, 9, 10])
])
def test_all_subsets_sum(test_input, expected):
    actual = all_subset_sums(test_input)
    actual.sort()
    expected.sort()

    assert len(actual) == len(expected)
    for i in range(len(actual)):
        assert actual[i] == expected[i]


@pytest.mark.parametrize('test_input,expected', [
    ([], [[]]),
    ([1], [[], [1]]),
    ([2, 5, 7], [[], [2], [5], [2, 5], [7], [2, 7], [5, 7], [2, 5, 7]]),
    ([2, 5, 5, 7], [[], [2], [5], [2, 5], [5, 5], [2, 5, 5], [7], [2, 7], [5, 7], [2, 5, 7], [5, 5, 7], [2, 5, 5, 7]]),
    ([1, 2, 3, 4], [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3], [4], [1, 4], [2, 4], [1, 2, 4], [3, 4],
                    [1, 3, 4], [2, 3, 4], [1, 2, 3, 4]])
])
def test_unique_subsets(test_input, expected):
    actual = unique_subsets(test_input)

    _assert_subset(actual, expected)


@pytest.mark.parametrize('test_input,target,expected', [
    ([], 1, []),
    ([1], 1, [[1]]),
    ([2, 5, 7], 7, [[2, 5], [7]]),
    ([3, 5, 5, 7], 10, [[5, 5], [3, 7]]),
    ([1, 2, 3, 4], 11, [])
])
def test_subset_with_target_sum(test_input, target, expected):
    actual = subset_with_target_sum(test_input, target)
    _assert_subset(actual, expected)

