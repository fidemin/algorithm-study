

def get_pi(pattern):
    length = len(pattern)
    pi = [0] * length

    for begin in range(1, length):
        for i in range(length-begin):
            if pattern[i] != pattern[begin + i]:
                break
            if pi[begin+i] == 0:
                pi[begin+i] = i+1
            #pi[begin + i] = max([i+1, pi[begin+i]])

    return pi


def kmp(text, pattern):
    t_len = len(text)
    p_len = len(pattern)
    pi = get_pi(pattern)

    begin = 0
    matched = 0
    result = []
    while begin <= t_len - p_len:
        if matched < p_len and text[begin + matched] == pattern[matched]:
            matched += 1
            if matched == p_len:
                result.append(begin)
        else:
            if matched == 0:
                begin += 1
            else:
                begin = begin + matched - pi[matched-1]
                matched = pi[matched-1]

    return result

if __name__ == "__main__":
    a = kmp("caababcdaaba", "aab")
    print(a)

    a = kmp("caabaabacbcdaaba", "aabaabac")
    print(a)

