//
// Created by fishy on 2025/10/15.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lifefunc.h"

// 交互模式
void interactive_mode(void) {
    char line[256];
    int x, y;

    printf("=== Interactive Mode ===\n");
    printf("Commands:\n");
    printf("  a x y  - Add live cell at (x,y)\n");
    printf("  r x y  - Remove cell at (x,y)\n");
    printf("  n      - Next generation\n");
    printf("  p      - Play continuously\n");
    printf("  q      - Quit\n\n");

    initialize_board();

    while (1) {
        display_board();
        printf("Enter command: ");
        // 读取整行输入
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;  // 读取失败或EOF
        }
        // 解析命令
        char command;
        if (strlen(line) > 0 && line[strlen(line)-1] == '\n') {
            line[strlen(line)-1] = '\0';
        }
        // 解析单个字符命令 (n, p, q)
        if (strlen(line) == 1) {
            command = line[0];
            switch (command) {
                case 'n':
                    next_generation();
                    printf("Advanced to next generation\n");
                    break;
                case 'p':
                    printf("Starting continuous play... Press Ctrl+C to stop\n");
                    play_continuous();
                    break;
                case 'q':
                    printf("Goodbye!\n");
                    return;
                default:
                    printf("Unknown command: %c\n", command);
                    break;
            }
        }
        // 解析带参数的命令 (a x y, r x y)
        else if (sscanf(line, "%c %d %d", &command, &x, &y) == 3) {
            switch (command) {
                case 'a':
                    add_cell(x, y);
                    printf("Added cell at (%d, %d)\n", x, y);
                    break;
                case 'r':
                    remove_cell(x, y);
                    printf("Removed cell at (%d, %d)\n", x, y);
                    break;
                default:
                    printf("Unknown command: %c\n", command);
                    break;
            }
        }
        else {
            printf("Invalid command format: %s\n", line);
            printf("Valid formats: 'n', 'p', 'q', 'a x y', 'r x y'\n");
        }
    }
}

// 批处理模式
void batch_mode(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }

    printf("=== Batch Mode: %s ===\n", filename);
    initialize_board();

    char command[10];
    int x, y;

    // 读取并执行文件中的命令
    while (fscanf(file, "%s", command) == 1) {
        if (strcmp(command, "a") == 0) {
            if (fscanf(file, "%d %d", &x, &y) == 2) {
                add_cell(x, y);
                printf("Added cell at (%d, %d)\n", x, y);
            }
        }
        else if (strcmp(command, "p") == 0) {
            printf("Starting continuous play from batch file...\n");
            play_continuous();
        }
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    printf("Conway's Game of Life\n");

    if (argc == 1) {
        // 交互模式
        interactive_mode();
    }
    else if (argc == 2) {
        // 批处理模式
        batch_mode(argv[1]);
    }
    else {
        // 错误：太多参数
        printf("Error: Too many arguments\n");
        printf("Usage: %s                 for interactive mode\n", argv[0]);
        printf("       %s <filename>      for batch mode\n", argv[0]);
        return 1;
    }

    return 0;
}