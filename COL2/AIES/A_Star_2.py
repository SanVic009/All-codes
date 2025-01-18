class Node:
    def __init__(self, data, level, fval):
        self.data = data
        self.level = level
        self.fval = fval

    def find(self, puzzle, value):
        """Find the position of the value in the puzzle."""
        for i in range(len(puzzle)):
            for j in range(len(puzzle[i])):
                if puzzle[i][j] == value:
                    return i, j
        return -1, -1

    def generate_child(self):
        """Generate child nodes by moving the empty space ('_') in all possible directions."""
        x, y = self.find(self.data, '_')
        val_list = [[x, y - 1], [x, y + 1], [x - 1, y], [x + 1, y]]  # possible moves: left, right, up, down
        children = []

        for i in val_list:
            child = self.shuffle(self.data, x, y, i[0], i[1])
            if child is not None:
                child_node = Node(child, self.level + 1, 0)
                children.append(child_node)

        return children

    def shuffle(self, puzzle, x1, y1, x2, y2):
        """Move the empty space and create a new configuration."""
        if 0 <= x2 < len(puzzle) and 0 <= y2 < len(puzzle[0]):
            temp_puz = [row[:] for row in puzzle]
            temp = temp_puz[x2][y2]
            temp_puz[x2][y2] = temp_puz[x1][y1]
            temp_puz[x1][y1] = temp
            return temp_puz
        else:
            return None

    def copy(self, root):
        """Create a deep copy of the puzzle."""
        temp = []
        for i in root:
            t = []
            for j in i:
                t.append(j)
            temp.append(t)
        return temp


class Puzzle:
    def __init__(self, size):
        self.n = size
        self.open = []
        self.closed = []

    def accept(self):
        """Accept the puzzle input from the user."""
        puz = []
        for i in range(self.n):
            temp = input().split(" ")
            puz.append(temp)
        return puz

    def h(self, start, goal):
        """Calculate the heuristic (Manhattan distance) for A*."""
        distance = 0
        for i in range(self.n):
            for j in range(self.n):
                if start[i][j] != '_':
                    x1, y1 = self.find(start, start[i][j])
                    x2, y2 = self.find(goal, start[i][j])
                    distance += abs(x1 - x2) + abs(y1 - y2)
        return distance

    def f(self, start, goal):
        """Calculate the f-value for the node."""
        return self.h(start.data, goal) + start.level

    def find(self, puzzle, value):
        """Find the position of a value in the puzzle."""
        for i in range(self.n):
            for j in range(self.n):
                if puzzle[i][j] == value:
                    return i, j
        return -1, -1

    def process(self):
        """Start solving the puzzle using A*."""
        print("Enter the start state matrix:")
        start = self.accept()
        print("Enter the goal state matrix:")
        goal = self.accept()

        start_node = Node(start, 0, 0)
        start_node.fval = self.f(start_node, goal)
        self.open.append(start_node)

        print("\nStarting the puzzle-solving process...\n")
        while True:
            if not self.open:
                print("No solution found.")
                break

            # Pop the node with the lowest f-value
            self.open.sort(key=lambda node: node.fval)
            cur = self.open.pop(0)

            # Display the current state
            print("Next state:")
            for row in cur.data:
                print(" ".join(row))

            # Check if the goal state is reached
            if cur.data == goal:
                print("\nGoal state reached!")
                break

            children = cur.generate_child()

            # Add children to the open list
            for child in children:
                child.fval = self.f(child, goal)
                self.open.append(child)


# Main entry point
sqn = int(input("Enter number of rows/columns in the puzzle problem (for NxN puzzle): "))
puz = Puzzle(sqn)
puz.process()