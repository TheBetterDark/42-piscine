import random

class Grid:
    def __init__(self):
        self.rows, self.cols, self.density = 20, 20, 0.4
        self.empty, self.obstacle, self.full = ' ', 'o', 'x'
        self.grid = [[self.obstacle if (random.random()*2) < self.density else self.empty for _ in range(self.cols)] for _ in range(self.rows)]

    def print_shit_grid(self):
        for s in self.row:
            print 

    def find_largest_square(self):
        dp = [[0]*self.cols for _ in range(self.rows)]
        max_size = 0
        max_index = (0, 0)

        for i in range(self.rows):
            for j in range(self.cols):
                if self.grid[i][j] == self.empty:
                    if i == 0 or j == 0:
                        dp[i][j] = 1
                    else:
                        dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) + 1

                    if dp[i][j] > max_size:
                        max_size = dp[i][j]
                        max_index = (i, j)

        for i in range(max_index[0] - max_size + 1, max_index[0] + 1):
            for j in range(max_index[1] - max_size + 1, max_index[1] + 1):
                self.grid[i][j] = self.full

if __name__ == "__main__":
    grid = Grid()
    grid.find_largest_square()
    grid.print_grid()
