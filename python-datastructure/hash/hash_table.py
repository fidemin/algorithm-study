
from collections import namedtuple


class HashNode(object):
    def __init__(self, key, value):
        self.key = key
        self.value = value

    def __repr__(self):
        return "Node(%s, %s)" % (self.key, self.value)


class StringHashTable(object):
    def __init__(self):
        self._ht = [[] for _ in range(16)]

    def get(self, key):
        pos = self._hash(key) & 0b1111

        for node in self._ht[pos]:
            if node.key == key:
                return node.value

        raise KeyError("key '%s' does not exist in hashtable" % key)

    def put(self, key, value):
        pos = self._hash(key) & 0b1111

        for node in self._ht[pos]:
            if node.key == key:
                node.value = value

        self._ht[pos].append(HashNode(key, value))


    def _hash(self, string):
        ret = 0
        for c in string:
            ret += ord(c)

        return ret



if __name__ == "__main__":
    ht = StringHashTable()
    try:
        ht.get("hi")
    except KeyError as e:
        print(e)

    ht.put("hi", "good")
    assert(ht.get("hi") == "good")
    ht.put("hi", "good_new")
    assert(ht.get("hi") == "good_new")
    ht.put("hi1", "good1")
    ht.put("hi2", "good2")
    ht.put("abc", "abc1")
    ht.put("aaaaaaaaaaaaa", "aaaaaaaaaa1")
    print(ht._ht)


