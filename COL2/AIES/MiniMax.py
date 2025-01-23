def evaluate(b):
    for row in range(3):
        if (b[row][0] == b[row][1] == b[row][2]):
            if (b[row][0] == 'X'):
                return 10
            elif (b[row][0] == 'O'):
                return -10
    
    for col in range(3):
        if (b[0][col] == b[1][col] == b[2][col]):
            if (b[0][col] == 'X'):
                return 10
            elif (b[0][col] == 'O'):
                return -10
        
    if (b[0][0] == b[1][1] == b[2][2]):
        if (b[0][0] == 'X'):
            return 10
        elif (b[0][0] == 'O'):
            return -10
    
    if (b[0][2] == b[1][1] == b[2][1]):
        if (b[0][2] == 'X'):
            return 10
        elif(b[0][2] == 'O'):
            return -10
        

def is_even(x):
    if (x%2 == 0):
        return True
    else:
        return False



class Board:
    def __init__(self):
        self.b= [
            ['-', '-', '-'],
            ['-', '-', '-'],
            ['-', '-', '-']
        ]
        

    def accept(self, x, y):
        if is_even(move_counter):
            self.b[x][y] = 'O'

        else:
            self.b[x][y] = 'X'

        move_counter += 1


    def print_board(self):
        print(f"{self.b[0][0]} | {self.b[0][1]} | {self.b[0][2]} ")
        print("-- --- --")
        print(f"{self.b[1][0]} | {self.b[1][1]} | {self.b[1][2]} ")
        print("-- --- --")
        print(f"{self.b[2][0]} | {self.b[2][1]} | {self.b[2][2]} ")

        
        
        
move_counter = 0
# val = evaluate(b)
# print(f"The value of the board is {val}")
brd = Board()

brd.print_board()

