import unittest

from p1_1 import dup_exist
from p1_2 import is_permutation

class TestIsDupExist(unittest.TestCase):
    def test_is_dup_exist(self):
        self.assertFalse(dup_exist("abcdefg"))
        self.assertFalse(dup_exist("-123*&("))
        self.assertTrue(dup_exist("-123*&(&"))
        self.assertTrue(dup_exist("dkghi1092hgk2j"))


class TestIsPermutation(unittest.TestCase):
    def test_is_permutation(self):
        self.assertTrue(is_permutation("abcde", "baced"))
        self.assertFalse(is_permutation("abcd ", "baced"))


if __name__ == "__main__":
    unittest.main()
