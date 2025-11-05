//
// Created by fishy on 2025/10/15.
//
#include "lifefunc.h"
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// 定义全局棋盘
char board[BOARD_SIZE][BOARD_SIZE];
void clear_screen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
// 跨平台延时（毫秒）
void delay_ms(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}
// 1. 初始化棋盘 - 全部设为死细胞
void initialize_board(void) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' '; // 空格表示死细胞
        }
    }
}

// 2. 显示棋盘 - 带边框
void display_board(void) {
    //clear_screen();
    printf("=== Conway's Game of Life ===\n");
    printf("Board Size: %dx%d\n\n", BOARD_SIZE, BOARD_SIZE);

    // 打印上边框
    for (int i = 0; i < BOARD_SIZE + 2; i++) {
        printf("-");
    }
    printf("\n");

    // 打印棋盘内容
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("|"); // 左边框
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
        }
        printf("|\n"); // 右边框
    }

    // 打印下边框
    for (int i = 0; i < BOARD_SIZE + 2; i++) {
        printf("-");
    }
    printf("\n");
}

// 3. 添加活细胞
void add_cell(int x, int y) {
    if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
        board[x][y] = 'X'; // 'X' 表示活细胞
    }
}

// 4. 移除细胞
void remove_cell(int x, int y) {
    if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
        board[x][y] = ' '; // 空格表示死细胞
    }
}

// 5. 下一代计算 - 先留空，后面实现
void next_generation(void) {
    // TODO: 实现生命游戏规则
    char new_board[BOARD_SIZE][BOARD_SIZE];

    // 初始化新棋盘
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            new_board[i][j] = ' ';
        }
    }

    // 应用生命游戏规则
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int live_neighbors = 0;

            // 检查8个邻居
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue; // 跳过自身

                    int ni = i + di;
                    int nj = j + dj;

                    // 检查边界
                    if (ni >= 0 && ni < BOARD_SIZE && nj >= 0 && nj < BOARD_SIZE) {
                        if (board[ni][nj] == 'X') {
                            live_neighbors++;
                        }
                    }
                }
            }

            // 应用规则
            if (board[i][j] == 'X') {
                // 活细胞
                if (live_neighbors == 2 || live_neighbors == 3) {
                    new_board[i][j] = 'X'; // 存活
                } else {
                    new_board[i][j] = ' '; // 死亡
                }
            } else {
                // 死细胞
                if (live_neighbors == 3) {
                    new_board[i][j] = 'X'; // 繁殖
                } else {
                    new_board[i][j] = ' '; // 保持死亡
                }
            }
        }
    }

    // 复制新棋盘到原棋盘
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = new_board[i][j];
        }
    }

}

void play_continuous(void) {
    int generation = 0;
    while (1) {
        printf("Generation: %d (Press Ctrl+C to stop)\n", generation++);
        display_board();
        next_generation();
        delay_ms(500); // 200毫秒延迟，便于观察
    }
}