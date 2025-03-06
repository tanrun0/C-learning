#include "saolei.h"
int main() {
    char showBoard[ROWS][COLS];
    char realBoard[ROWS+2][COLS+2];

    // ��ʼ������
    InitshowBoard(showBoard, '*');
    InitrealBoard(realBoard, '0');

    // ������
    PlaceMines(realBoard);
    int win = 0;
    while (win < ROWS * COLS - MINES) {
        DispshowBoard(showBoard);
        int x, y;
        std::cout << "������Ҫ�Ų��λ�� (�� ��): ";
        std::cin >> x >> y;

        if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
            std::cout << "�����λ����Ч�����������롣" << std::endl;
            continue;
        }

        if (FindMines(showBoard, realBoard, x, y)) {
            std::cout << "���ź�����ȵ����ˣ���Ϸʧ�ܣ�" << std::endl;
            DisprealBoard(realBoard);
            break;
        }
        else {
            win++;
        }
        if (win == ROWS * COLS - MINES) {
            std::cout << "��ϲ�㣬���׳ɹ�����Ϸʤ����" << std::endl;
            DisprealBoard(realBoard);
            break;
        }
    }

    return 0;
}