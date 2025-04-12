#include "saolei.h"
int main() {
    char showBoard[ROWS][COLS];
    char realBoard[ROWS+2][COLS+2];

    // 初始化棋盘
    InitshowBoard(showBoard, '*');
    InitrealBoard(realBoard, '0');

    // 布置雷
    PlaceMines(realBoard);
    int win = 0;
    while (win < ROWS * COLS - MINES) {
        DispshowBoard(showBoard);
        int x, y;
        std::cout << "请输入要排查的位置 (行 列): ";
        std::cin >> x >> y;

        if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
            std::cout << "输入的位置无效，请重新输入。" << std::endl;
            continue;
        }

        if (FindMines(showBoard, realBoard, x, y)) {
            std::cout << "很遗憾，你踩到雷了，游戏失败！" << std::endl;
            DisprealBoard(realBoard);
            break;
        }
        else {
            win++;
        }
        if (win == ROWS * COLS - MINES) {
            std::cout << "恭喜你，排雷成功，游戏胜利！" << std::endl;
            DisprealBoard(realBoard);
            break;
        }
    }

    return 0;
}