
def swap(lst, i, j):
    tmp = lst[i]
    lst[i] = lst[j]
    lst[j] = tmp


def biggerIsGreater(w):
    l = len(w)
    w_list = list(w)
    for i in range(l-1, -1, -1):
        #print("i:", i)
        j = l-1
        while (i < j):
            #print("\tj:", j)
            if w_list[j] > w_list[i]:
                swap(w_list, i, j)
                w_list[i+1:] = sorted(w_list[i+1:])
                return "".join(w_list)
            j -= 1
    return "no answer"

if __name__ == "__main__":
    w_list = biggerIsGreater("abcd")
    print(w_list)
