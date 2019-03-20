
from collections import Counter

def is_perm_of_palindrome(s):
    counter = Counter(s)

    num_of_odds = 0
    for c, n in counter.items():
        if n % 2 != 0:
            num_of_odds += 1

        if num_of_odds > 1:
            return False

    return num_of_odds == 0 or num_of_odds == 1



if __name__ == "__main__":
    assert(False == is_perm_of_palindrome("abcde"))
    assert(True == is_perm_of_palindrome("ababc"))
