# 编译器设置
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
TARGET = life

# 源文件
SOURCES = lifefunc.c playlife.c
HEADERS = lifefunc.h
OBJECTS = $(SOURCES:.c=.o)

# 默认目标
all: $(TARGET)

# 生成可执行文件
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# 编译规则
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# 运行程序
run: $(TARGET)
	./$(TARGET)

# 清理
clean:
	rm -f $(OBJECTS) $(TARGET)

# 重新编译
rebuild: clean all

# 显示帮助信息
help:
	@echo "可用命令:"
	@echo "  make       - 编译程序 (生成 $(TARGET))"
	@echo "  make run   - 编译并运行程序"
	@echo "  make debug - 编译调试版本"
	@echo "  make clean - 清理编译生成的文件"
	@echo "  make rebuild - 重新编译"
	@echo "  make help  - 显示此帮助信息"
.PHONY: all run clean rebuild
