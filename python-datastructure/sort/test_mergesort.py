import pytest

from .mergesort import sort


def _sort_testcases() -> list[tuple]:
    return [
        ([], []),
        ([1], [1]),
        ([2, 1], [1, 2]),
        ([5, 8, 1, 2, 23, 4], [1, 2, 4, 5, 8, 23]),
        ([5, 12, 13, 1, 2, 23, 4], [1, 2, 4, 5, 12, 13, 23]),
        ([5, 12, 12, 1, 1, 23, 4], [1, 1, 4, 5, 12, 12, 23]),
    ]


@pytest.mark.parametrize('input_,expected', _sort_testcases())
def test_mergesort(input_: list[int], expected: list[int]):
    sort(input_)
    assert input_ == expected
