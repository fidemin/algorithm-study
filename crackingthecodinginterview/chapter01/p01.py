
def dup_exist(s):
    if len(s) > 128:
        return True

    chars = 0

    for c in s:
        if chars & (1 << ord(c)):
            return True

        chars |= 1 << ord(c)

    return False
