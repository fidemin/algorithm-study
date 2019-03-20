

def editable(s1, s2):
    len1 = len(s1)
    len2 = len(s2)
    if abs(len1 - len2) > 1:
        return False

    diff = 0
    cr1 = 0
    cr2 = 0

    while cr1 < len1 and cr2 < len2:
        if s1[cr1] == s2[cr2]:
            cr1 += 1
            cr2 += 1
        else:
            if diff == 1:
                return False
            else:
                diff = 1

            if len1 < len2:
                cr2 += 1
            elif len1 == len2:
                cr1 += 1
                cr2 += 1
            else:
                cr1 += 1

    return True

if __name__ == "__main__":
    assert(True == editable("pale", "ple"))
    assert(True == editable("pales", "pale"))
    assert(True == editable("pale", "bale"))
    assert(False == editable("pale", "bake"))
