
def fast_sum(n):
    if n == 1:
        return 1

    if n % 2 == 0:
        return (n >> 1)**2 + (fast_sum(n >> 1) << 1)
    else:
        return (n >> 1)**2 + (fast_sum(n >> 1) << 1) + n


if __name__ == "__main__":
    print(fast_sum(10)) 
    print(fast_sum(9)) 
    print(fast_sum(8)) 
    print(fast_sum(7)) 
