
cache = [[None] * 10000 for _ in range(10000)]

def bino(n, r):
    if r == 0 or n == 1:
        return 1

    if cache[n][r] is not None:
        return cache[n][r]

    ret =  bino(n-1, r-1) + bino(n-1, r)
    cache[n][r] = ret
    return ret



def main():
    print(bino(100, 4))

if __name__ == "__main__":
    main()
