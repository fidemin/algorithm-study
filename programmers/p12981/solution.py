

def solution(n, words):
    dups = {}
    first = 0
    prev = words[0][0]

    for i, word in enumerate(words):
        if prev != word[0]:
            first = i
            break

        if dups.get(word, False):
            first = i
            break

        dups[word] = True
        prev = word[len(word)-1]

    if first == 0:
        return [0, 0]

    return [(first%n)+1, (first//n)+1]



if __name__ == "__main__":
    print(solution(
        3,
        ["tank", "kick", "know", "wheel", "land", "dream", "mother", "robot","tank"])
    )

    print(solution(2, ["hello", "one", "even", "never", "now", "world", "draw"]))
