#include "saolei.h" // 自定义的文件用" "来包含

void InitshowBoard(char board[ROWS][COLS], char ch) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			board[i][j] = ch;
		}
	}
}

void InitrealBoard(char board[ROWS+2][COLS+2], char ch) {
    for (int i = 0; i < ROWS+2; i++) {
        for (int j = 0; j < COLS+2; j++) {
            board[i][j] = ch;
        }
    }
}

void DispshowBoard(char board[ROWS][COLS]) {
    std::cout << "  ";
    //先打印表头
    for (int i = 0; i < COLS; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        std::cout << i << " "; // 每一行之前先打印行头
        for (int j = 0; j < COLS; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void DisprealBoard(char board[ROWS+2][COLS+2]) {
    std::cout << "  ";
    //先打印表头
    for (int i = 1; i < COLS + 1; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (int i = 1; i < ROWS + 1; ++i) {
        std::cout << i << " "; // 每一行之前先打印行头
        for (int j = 1; j < COLS + 1; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void PlaceMines(char realboard[ROWS+2][COLS+2]) {
    int count = MINES;
    while (count) {
        int x = rand() % ROWS + 1; // x :[1, 9]
        int y = rand() % COLS + 1; // y :[1, 9]
        if (realboard[x][y] == '0') {
            realboard[x][y] = '1';
            count--;
        }
    }
}

int CountMines(char realboards[ROWS+2][COLS+2], int x, int y) {
    return (realboards[x - 1][y - 1] + realboards[x - 1][y] + realboards[x - 1][y + 1] + realboards[x][y - 1] + realboards[x][y + 1] + \
        realboards[x + 1][y - 1] + realboards[x + 1][y] + realboards[x + 1][y + 1] - 8 * '0');
}

bool FindMines(char showboard[ROWS][COLS], char realboard[ROWS+2][COLS+2], int x, int y) {
    if (realboard[x][y] == '1') {
        return true;
    }
    int count = CountMines(realboard, x, y);
    showboard[x][y] = count + '0';
    return false;
}
