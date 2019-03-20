
def dup_exist(s):
    if len(s) > 128:
        return True

    chars = 0

    for c in s:
        if chars & (1 << ord(c)):
            return True

        chars |= 1 << ord(c)

    return False

if __name__ == "__main__":
    assert(False == dup_exist("abcdefg"))
    assert(False == dup_exist("-123*&("))
    assert(True == dup_exist("-123*&(&"))
    assert(True == dup_exist("dkghi1092hgk2j"))
