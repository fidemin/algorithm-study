import pytest
from binary_search import find_left_most_position


@pytest.mark.parametrize('test_input,target,expected', [
    ([], 0, -1),
    ([1], 1, 0),
    ([1, 1], 1, 0),
    ([1, 2, 3], 2, 1),
    ([2, 2, 3, 4], 2, 0),
    ([1, 2, 2, 3, 4], 2, 1),
    ([1, 2, 2, 4, 5], 3, -1),
    ([1, 2, 2, 4, 4], 4, 3),
])
def test_find_left_most_position(test_input, target, expected):
    actual = find_left_most_position(test_input, target)
    assert actual == expected
