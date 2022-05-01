# Traveling Salesman Problem using Branch and Bound.
import math
maxsize = float('inf')

# Function to copy temporary solution
# to the final solution


def copyToFinal(curr_path):
    final_path[:matrix_size + 1] = curr_path[:]
    final_path[matrix_size] = curr_path[0]

# Function to find the minimum edge cost
# having an end at the vertex i


def firstMin(matrix, i):
    min = maxsize
    for k in range(matrix_size):
        if matrix[i][k] < min and i != k:
            min = matrix[i][k]

    return min

# function to find the second minimum edge
# cost having an end at the vertex i


def secondMin(matrix, i):
    first, second = maxsize, maxsize
    for j in range(matrix_size):
        if i == j:
            continue
        if matrix[i][j] <= first:
            second = first
            first = matrix[i][j]

        elif(matrix[i][j] <= second and
                matrix[i][j] != first):
            second = matrix[i][j]

    return second

# function that takes as arguments:
# curr_bound -> lower bound of the root node
# curr_weight-> stores the weight of the path so far
# level-> current level while moving
# in the search space tree
# curr_path[] -> where the solution is being stored
# which would later be copied to final_path[]


def TSPRec(matrix, curr_bound, curr_weight,
           level, curr_path, visited):
    global final_res

    # base case is when we have reached level matrix_size
    # which means we have covered all the nodes once
    if level == matrix_size:

        # check if there is an edge from
        # last vertex in path back to the first vertex
        if matrix[curr_path[level - 1]][curr_path[0]] != 0:

            # curr_res has the total weight
            # of the solution we got
            curr_res = curr_weight + matrix[curr_path[level - 1]][curr_path[0]]
            if curr_res < final_res:
                copyToFinal(curr_path)
                final_res = curr_res
        return

    for i in range(matrix_size + 1):
        print(curr_path[i] + 1, end=" ")
    print("")

    # for any other level iterate for all vertices
    # to build the search space tree recursively
    for i in range(matrix_size):
        # Consider next vertex if it is not same
        # (diagonal entry in matrixacency matrix and
        # not visited already)
        if (matrix[curr_path[level-1]][i] != 0 and
                visited[i] == False):
            temp = curr_bound
            curr_weight += matrix[curr_path[level - 1]][i]

            # different computation of curr_bound
            # for level 2 from the other levels
            if level == 1:
                curr_bound -= ((firstMin(matrix, curr_path[level - 1]) +
                                firstMin(matrix, i)) / 2)
            else:
                curr_bound -= ((secondMin(matrix, curr_path[level - 1]) +
                                firstMin(matrix, i)) / 2)

            # curr_bound + curr_weight is the actual lower bound
            # for the node that we have arrived on.
            # If current lower bound < final_res,
            # we need to explore the node further
            if curr_bound + curr_weight < final_res:
                curr_path[level] = i
                visited[i] = True

                # call TSPRec for the next level
                TSPRec(matrix, curr_bound, curr_weight,
                       level + 1, curr_path, visited)

            # Else we have to prune the node by resetting
            # all changes to curr_weight and curr_bound
            curr_weight -= matrix[curr_path[level - 1]][i]
            curr_bound = temp
            # Also reset the visited array
            visited = [False] * len(visited)
            for j in range(level):
                if curr_path[j] != -1:
                    visited[curr_path[j]] = True

# This function sets up final_path


def TSP(matrix):

    # Calculate initial lower bound for the root node
    # using the formula 1/2 * (sum of first min +
    # second min) for all edges. Also initialize the
    # curr_path and visited array
    curr_bound = 0
    curr_path = [-1] * (matrix_size + 1)
    visited = [False] * matrix_size

    # Compute initial bound
    for i in range(matrix_size):
        curr_bound += (firstMin(matrix, i) + secondMin(matrix, i))

    # Rounding off the lower bound to an integer
    curr_bound = math.ceil(curr_bound / 2)

    # We start at vertex 1 so the first vertex
    # in curr_path[] is 0
    visited[0] = True
    curr_path[0] = 0

    # Call to TSPRec for curr_weight
    # equal to 0 and level 1
    TSPRec(matrix, curr_bound, 0, 1, curr_path, visited)


path = "./test5.txt"

try:
    fr = open(path, 'r')
    node_str = fr.read().split(" ")
    matrix_size = int(node_str[0])
    node_str.pop(0)
    # Adjacency matrix for the given graph
    matrix = []
    for i in range(0, matrix_size):
        matrix.append(node_str[i * matrix_size: i * matrix_size + matrix_size])

    for i in range(0, matrix_size):
        for j in range(0, matrix_size):
            matrix[i][j] = int(matrix[i][j])

    # final_path[] stores the final solution
    # i.e. the // path of the salesman.
    final_path = [None] * (matrix_size + 1)

    # visited[] keeps track of the already
    # visited nodes in a particular path
    visited = [False] * matrix_size

    # Stores the final minimum weight
    # of shortest tour.
    final_res = maxsize
    print("路徑變化 : ")
    TSP(matrix)
    for i in range(matrix_size + 1):
        print(final_path[i] + 1, end=" ")
    print("\n節點順序 : ", end=' ')
    for i in range(matrix_size + 1):
        if i != matrix_size:
            print(final_path[i] + 1, end='->')
        else:
            print(final_path[i] + 1)
    # last_route = int(final_path[matrix_size - 1])
    print("總成本 :", final_res + matrix[final_path[matrix_size - 1]][0], "(繞回原點)",
          ", ", final_res, "(只到node", final_path[matrix_size - 1] + 1, "的成本)")
except IOError:
    print('ERROR: can not found ' + path)
    if fr:
        fr.close()
