
class JumpGame(object):
    def __init__(self, board):
        self._board = board
        self._size = len(board)
        self._cache = [[None] * self._size for _ in range(self._size)]

    def jump(self):
        return self._jump_at(0, 0)

    def _jump_at(self, y, x):
        n = self._size
        if x >= n or y >= n:
            return False

        if y == n-1 and x == n-1:
            return True

        if self._cache[y][x] is not None:
            return self._cache[y][x]

        jump_size = self._board[y][x]

        self._cache[y][x] = self._jump_at(y + jump_size, x) or self._jump_at(y, x + jump_size)
        return self._cache[y][x]


def jump(board, y, x):
    n = len(board)
    if x >= n or y >= n:
        return False

    if y == n-1 and x == n-1:
        return True

    jump_size = board[y][x]

    return jump(board, y + jump_size, x) or jump(board, y, x + jump_size)

if __name__ == "__main__":
    board1 = (
        (2, 5, 1, 6),
        (3, 1, 1, 2),
        (3, 2, 3, 2),
        (1, 1, 3, 1)
    )

    assert(JumpGame(board1).jump())

    board2 = (
        (2, 5, 1, 6),
        (3, 1, 1, 3),
        (3, 2, 1, 2),
        (1, 1, 3, 1)
    )

    assert(False == JumpGame(board2).jump())
