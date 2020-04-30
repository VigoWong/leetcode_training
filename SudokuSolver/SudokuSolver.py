class Solution:
    def getSudokuSet(self, posX, posY, board):
        x = posX // 3
        y = posY // 3
        ret = set()

        for yPos in range(y * 3, (y + 1) * 3):
            for xPos in range(x * 3, (x + 1) * 3):
                if board[y][x].isdigit():
                    ret = ret | set(board[yPos][xPos])

        complete = set([str(i) for i in range(1, 10)])
        new = complete - ret
        return new

    def getRowsSet(self, posY, board):
        ret = set()
        for x in range(len(board[posY])):
            if (board[posY][x].isdigit()):
                ret = ret | set(board[posY][x])
        complete = set([str(i) for i in range(1, 10)])
        new = complete - ret
        return new

    def getColSet(self, posX, board):
        ret = set()
        for y in range(len(board)):
            if board[y][posX].isdigit():
                ret = ret | set(board[y][posX])
        complete = set([str(i) for i in range(1, 10)])
        new = complete - ret
        return new

    def solveSudoku(self, board):
        """
        Do not return anything, modify board in-place instead.
        """
        flag = False
        while not flag:
            flag = True
            for y in range(len(board)):

                for x in range(len(board[0])):

                    if not board[y][x].isdigit():
                        rowSet = self.getRowsSet(y, board)
                        colSet = self.getColSet(x, board)
                        SuSet = self.getSudokuSet(x, y, board)

                        digit = list(rowSet & colSet & SuSet)

                        if (len(digit) == 1):
                            board[y][x] = digit[0]
                        else:
                            flag = False

        for y in range(len(board)):
            for x in range(len(board[0])):
                print(board[y][x], end='  ')
            print("")


if __name__ == '__main__':
    arr = [["5", "3", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "."],
           [".", "9", "8", ".", ".", ".", ".", "6", "."], ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
           ["4", ".", ".", "8", ".", "3", ".", ".", "1"], ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
           [".", "6", ".", ".", ".", ".", "2", "8", "."], [".", ".", ".", "4", "1", "9", ".", ".", "5"],
           [".", ".", ".", ".", "8", ".", ".", "7", "9"]]

    c = Solution()
    c.solveSudoku(arr)
