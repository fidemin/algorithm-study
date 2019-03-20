
def alphabet_to_num(c):
    return ord(c) - ord('A')

def is_perm_of_palindrome(s):
    alphabit = 0

    # toggling
    for c in s:
        alphabit ^= 1 << alphabet_to_num(c)


    # alphabit의 이진수가 0이거나 1을 하나만 가지고 있다면 True
    if alphabit == 0 or alphabit & (alphabit - 1) == 0:
        return True

    return False


if __name__ == "__main__":
    assert(False == is_perm_of_palindrome("abcde"))
    assert(True == is_perm_of_palindrome("ababc"))
    assert(True == is_perm_of_palindrome("elnelelelabccba"))
