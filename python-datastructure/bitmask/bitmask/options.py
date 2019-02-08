
full_options = (1 << 10) - 1

def full_options(n):
    """
    n개의 옵션이 모두 on 인 비트마스트 값을 리턴한다.
    """
    return (1 << n) -1


def add_option(options, p):
    """
    p 위치의 옵션을 킨다.
    """
    return options | (1 << p)


def delete_option(options, p):
    """
    p 위치의 옵션을 삭제한다.
    """
    return options & ~(1 << p)


def is_option_on(options, p):
    """
    p 위치의 옵션이 켜져있는지 확인한다.
    """
    return (options & (1 << p)) != 0


def toggle_option(options, p):
    """
    p 위치의 옵션을 토글한다.
    """
    return options ^ (1 << p)


def add(option1, option2):
    """
    합집합
    """
    return option1 | option2


def intersection(option1, option2):
    """
    교집합
    """
    return option1 & option2


def difference(option1, option2):
    """
    차집합
    """
    return a & ~b


def toggle(option1, option2):
    """
    토글링. 둘중 하나만 포함된 원소만 on됨
    """
    return option1 ^ option2


def bit_count(option):
    return bin(options).count("1")


def trailing_zeros(option):
    bits = bin(option)
    return len(bits) - len(bits.rstrip('0'))


def first_option(option):
    return option & (-option)


def delete_first_option(option):
    return option & (option - 1)

def partial_options(option):
    subset = option
    while subset != 0:
        yield subset
        subset = (subset - 1) & option





if __name__ == "__main__":
    n = 4
    options = full_options(n)
    print("options:", bin(options))
    options = delete_option(options, 2)
    print("options - 100:", bin(options))
    options = add_option(options, 2)
    print("options + 100:", bin(options))

    assert(3 == trailing_zeros(40))
    assert(8 == first_option(40))
    assert(32 == delete_first_option(40))

    for partial_option in partial_options(56):
        print(bin(partial_option))
