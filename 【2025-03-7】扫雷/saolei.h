#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

// 定义棋盘大小

const int ROWS = 9;
const int COLS = 9;
// 定义雷的数量
const int MINES = 10;

// 1, 有两个棋盘，9 * 9 和 11 * 11，9 * 9用来展示，11 * 11用来判断以及计算周边的雷的数目
// 函数：1，初始化棋盘；2，打印棋盘；3，布置雷；4，排查且判断单次结果
// 逻辑：先初始化，然后布置雷，然后打印棋盘，然后用户排查，
// 判断是否开到雷（开到：游戏结束，打印真实结果，没开到：展示当前位置周边有多少雷

// 初始化棋盘
void InitshowBoard(char showboard[ROWS][COLS], char ch);
void InitrealBoard(char showboard[ROWS + 2][COLS + 2], char ch);
// 打印棋盘
void DispshowBoard(char board[ROWS][COLS]);
void DisprealBoard(char board[ROWS + 2][COLS + 2]);
// 布置雷
void PlaceMines(char realboard[ROWS + 2][COLS + 2]);
// 排查雷
bool FindMines(char showboard[ROWS][COLS], char realboard[ROWS + 2][COLS + 2], int x, int y);
// 数周边有多少个雷
int CountMines(char realboard[ROWS + 2][COLS + 2], int x, int y);
