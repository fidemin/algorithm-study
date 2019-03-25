
def compress(string):
    char = None
    count = 0
    ret = []

    for c in string:
        if char != c:
            if count > 0:
                ret.append(char)
                ret.append(str(count))

            char = c
            count = 1
        else:
            count += 1

    ret.append(char)
    ret.append(str(count))

    return "".join(ret)


def compress_or_return(string):
    n = len(string)
    char = None
    count = 0
    ret = []

    for i, c in enumerate(string, 1):
        if char != c:
            if count > 0:
                ret.append(char)
                ret.append(str(count))

                # 미리 길이를 비교한다. 항상 뒤에는 남은 문자가 있으므로
                # 남은 문자의 최소 길이는 2이다.
                # 즉, 현재까지 압축 문자 길이와 2의 합이 n 보다 크다면 중지해도 된다.
                if len(ret) + 2 > n:
                    return string

            char = c
            count = 1
        else:
            count += 1

    ret.append(char)
    ret.append(str(count))

    return "".join(ret)


if __name__ == "__main__":
    assert("a2b1c5a3" == compress_or_return("aabcccccaaa"))
    assert("aabcdh" == compress_or_return("aabcdh"))
    assert("aabcddd" == compress_or_return("aabcddd"))
    assert("a1b1c5" == compress_or_return("abccccc"))
    assert("abccc" == compress_or_return("abccc"))

