//
// Created by fishy on 2025/10/15.
//

#ifndef LIFE_LIFEFUNC_H
#define LIFE_LIFEFUNC_H
#define BOARD_SIZE 40

// 声明全局棋盘（在lifefunc.c中定义）
extern char board[BOARD_SIZE][BOARD_SIZE];

// 核心功能函数声明
void initialize_board(void);     // 初始化一个空棋盘
void display_board(void);        // 在终端打印当前棋盘
void add_cell(int x, int y);     // 在(x,y)位置添加一个活细胞
void remove_cell(int x, int y);  // 在(x,y)位置移除一个细胞
void next_generation(void);      // 计算并更新到下一代
void clear_screen(void);               // 跨平台清屏
void play_continuous(void);            // 连续播放模式

#endif //LIFE_LIFEFUNC_H