#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

// �������̴�С

const int ROWS = 9;
const int COLS = 9;
// �����׵�����
const int MINES = 10;

// 1, ���������̣�9 * 9 �� 11 * 11��9 * 9����չʾ��11 * 11�����ж��Լ������ܱߵ��׵���Ŀ
// ������1����ʼ�����̣�2����ӡ���̣�3�������ף�4���Ų����жϵ��ν��
// �߼����ȳ�ʼ����Ȼ�����ף�Ȼ���ӡ���̣�Ȼ���û��Ų飬
// �ж��Ƿ񿪵��ף���������Ϸ��������ӡ��ʵ�����û������չʾ��ǰλ���ܱ��ж�����

// ��ʼ������
void InitshowBoard(char showboard[ROWS][COLS], char ch);
void InitrealBoard(char showboard[ROWS + 2][COLS + 2], char ch);
// ��ӡ����
void DispshowBoard(char board[ROWS][COLS]);
void DisprealBoard(char board[ROWS + 2][COLS + 2]);
// ������
void PlaceMines(char realboard[ROWS + 2][COLS + 2]);
// �Ų���
bool FindMines(char showboard[ROWS][COLS], char realboard[ROWS + 2][COLS + 2], int x, int y);
// ���ܱ��ж��ٸ���
int CountMines(char realboard[ROWS + 2][COLS + 2], int x, int y);
