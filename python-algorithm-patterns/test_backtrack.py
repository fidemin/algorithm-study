import pytest

from backtrack import permutation


def _assert_list_of_list(list1, list2):
    assert len(list1) == len(list2)
    list1.sort()
    list2.sort()

    for i in range(len(list1)):
        s1 = list1[i]
        s2 = list2[i]

        assert len(s1) == len(s2)
        for j in range(len(s1)):
            assert s1[j] == s2[j]


@pytest.mark.parametrize('test_input,expected', [
    ([], []),
    ([1], [[1]]),
    ([1, 2], [[1, 2], [2, 1]]),
    ([1, 2, 3], [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]])
])
def test_permutation(test_input, expected):
    actual = permutation(test_input)
    _assert_list_of_list(actual, expected)
