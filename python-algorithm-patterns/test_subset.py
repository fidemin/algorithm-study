import pytest
from subset import all_subsets


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
