#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 200
#define COLS 200
#define DENSITY 0.4

char grid[ROWS][COLS];
char empty = ' ';
char obstacle = 'o';
char full = 'x';

void initialize_grid() {
    srand(time(NULL)); 
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ((rand() / (double)RAND_MAX * 2) < DENSITY) {
                grid[i][j] = obstacle;
            } else {
                grid[i][j] = empty;
            }
        }
    }
}

void print_grid() {
	FILE *file = fopen("out.txt", "w");
	if (file == NULL) {
		printf("Error opening file!\n");
		return;
	}

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			fprintf(file, "%c", grid[i][j]);
		}
		fprintf(file, "\n");
	}

	fclose(file);
}

void find_largest_square() {
    int dp[ROWS][COLS] = {0};
    int max_size = 0;
    int max_index_i = 0;
    int max_index_j = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == empty) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    int min_prev = dp[i][j-1];
                    if (dp[i-1][j] < min_prev) min_prev = dp[i-1][j];
                    if (dp[i-1][j-1] < min_prev) min_prev = dp[i-1][j-1];
                    dp[i][j] = min_prev + 1;
                }
                if (dp[i][j] > max_size) {
                    max_size = dp[i][j];
                    max_index_i = i;
                    max_index_j = j;
                }
            }
        }
    }

    for (int i = max_index_i - max_size + 1; i <= max_index_i; i++) {
        for (int j = max_index_j - max_size + 1; j <= max_index_j; j++) {
            grid[i][j] = full;
        }
    }
}

int main() {
    initialize_grid();
    find_largest_square();
    print_grid();
    return 0;
}