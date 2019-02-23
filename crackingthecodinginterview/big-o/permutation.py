
count = 0

def permutation_rec(s, prefix):
    global count
    count+=1
    if len(s) == 0:
        print(prefix)
    else:
        for i in range(len(s)):
            permutation_rec(s[:i] + s[i+1:], prefix + s[i])


def permutation(s):
    permutation_rec(s, "")


if __name__ == "__main__":
    permutation("abcd")
    print(count)
