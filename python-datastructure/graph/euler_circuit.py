

def euler_circuit(adj, circuit, here):
    for there in range(len(adj)):
        if adj[here][there] > 0:
            adj[here][there] -= 1
            adj[there][here] -= 1
            print("here: %d, there: %d, circuit: %s" % (here, there, circuit))
            euler_circuit(adj, circuit, there)

    circuit.append(here)
    print(circuit)


if __name__ == "__main__":
    adj = [
        [0, 1, 0, 1, 0, 0],
        [1, 0, 1, 0, 0, 0],
        [0, 1, 0, 1, 1, 1],
        [1, 0, 1, 0, 0, 0],
        [0, 0, 1, 0, 0, 1],
        [0, 0, 1, 0, 1, 0]
    ]

    circuit = []
    euler_circuit(adj, circuit, 0)
    circuit.reverse()
    print("result:%s" % circuit)
