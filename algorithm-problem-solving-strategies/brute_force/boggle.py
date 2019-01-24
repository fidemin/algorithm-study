

dyx = ((-1, -1), (0, -1), (1, -1), (1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0))


def in_range(board, y, x):
    y_range = len(board) - 1
    x_range = len(board[0]) - 1
    return y >= 0 and y <= y_range and x >= 0 and x <= x_range 

def has_word(board, y, x, word):
    if not in_range(board, y,x):
        return False

    if word[0] != board[y][x]:
        return False

    if len(word) == 1:
        return True

    for i in range(8):
        nextY = y + dyx[i][0]
        nextX = x + dyx[i][1]
        if has_word(board, nextY, nextX, word[1:]):
            return True


if __name__ == "__main__":
    board = (
        "URLPM",
        "XPRET",
        "GIAET",
        "XTNZY",
        "XOQRS"
    )
    has_word = has_word(board, 1, 1, "PRETTY")
    assert(has_word is True)
