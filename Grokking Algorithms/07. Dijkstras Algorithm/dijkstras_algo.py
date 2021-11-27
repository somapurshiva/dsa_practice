# graph = {
#     "start": {
#         "a": 6,
#         "b": 2
#     },
#     "a": {
#         "fin": 1
#     },
#     "b": {
#         "a": 3,
#         "fin": 5
#     },
#     "fin": {}
# }

# graph = {
#     "start": {
#         "a": 5,
#         "b": 2
#     },
#     "a": {
#         "c": 4,
#         "d": 2
#     },
#     "b": {
#         "a": 8,
#         "d": 7
#     },
#     "c": {
#         "d": 6,
#         "fin": 3
#     },
#     "d": {
#         "fin": 1
#     },
#     "fin": {}
# }

# graph = {
#     "start": {
#         "a": 10
#     },
#     "a": {
#         "b": 20
#     },
#     "b": {
#         "fin": 30,
#         "c": 1
#     },
#     "c": {
#         "a": 1
#     },
#     "fin": {}
# }

graph = {
    "start": {
        "a": 2,
        "b": 2
    },
    "a": {
        "fin": 2,
        "c": 2
    },
    "b": {
        "a": 2
    },
    "c": {
        "b": -1,
        "fin": 2
    },
    "fin": {}
}

processed = []


def find_lowest_cost_node(costs):
    lowest_cost = float("inf")
    lowest_cost_node = None
    for node in costs:
        cost = costs[node]
        if cost < lowest_cost and node not in processed:
            lowest_cost = cost
            lowest_cost_node = node
    return lowest_cost_node


if __name__ == '__main__':
    infinity = float("inf")
    costs = {}
    parents = {}
    # Process the nodes nearest to the start node first
    for node in graph["start"].keys():
        costs[node] = graph["start"][node]
        parents[node] = "start"
    # if "fin" not in costs:
    #     costs["fin"] = infinity
    # if "fin" not in parents:
    #     parents["fin"] = None
    # Process other nodes after the first level now
    node = find_lowest_cost_node(costs)
    while node is not None:
        cost = costs[node]
        neighbors = graph[node]
        for n in neighbors.keys():
            if n not in costs:
                costs[n] = infinity
            if n not in parents:
                parents[n] = None
            new_cost = cost + neighbors[n]
            if costs[n] > new_cost:
                costs[n] = new_cost
                parents[n] = node

        processed.append(node)
        node = find_lowest_cost_node(costs)

    # Finally print the route
    if parents["fin"] is not None:
        route = " -> fin"
        start_node = parents["fin"]
        while start_node != "start":
            route = " -> " + start_node + route
            start_node = parents[start_node]
        route = "start" + route
        print(route)
        print("Cost: " + str(costs["fin"]))