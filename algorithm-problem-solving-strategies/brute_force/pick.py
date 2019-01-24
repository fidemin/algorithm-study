
def pick_brute(n):
    total_count = 0
    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                for l in range(k+1, n):
                    print("(", i, j, k, l, ")")
                    total_count += 1

    print("total count:", total_count)

def pick_recursive(n, picked, num_to_pick):
    if num_to_pick is 0:
        print(picked)

    smallest = picked[len(picked)-1]+1 if picked else 0
    num_to_pick -= 1
    for i in range(smallest, n):
        picked.append(i)
        pick_recursive(n, picked, num_to_pick)
        picked.pop()

def pick(n, num_to_pick):
    picked = []
    pick_recursive(n, picked, num_to_pick)

if __name__ == "__main__":
    pick_brute(6)
    pick(6, 4)
    
    
