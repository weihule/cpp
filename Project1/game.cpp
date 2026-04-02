#include "game.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>


// 全局变量定义
int snakeX[400], snakeY[400];
int foodX, foodY;
int dir;
int len;
bool gameOver;
int score;
const int opposite[] = { 2, 3, 0, 1 };


void GenerateFood() {
	bool onSnake = true;	// 食物在蛇身上标记
	while (onSnake) {
		foodX = rand() % width;
		foodY = rand() % height;
		onSnake = false;

		for (int i = 0; i < len; i++) {
			if (snakeX[i] == foodX && snakeY[i] == foodY) {
				onSnake = true;
				break;	// 终止当前for循环检查，继续进行while
			}
		}
	}
}

void SetUp() {
	srand((unsigned)time(0));
	gameOver = false;
	dir = 1;
	len = 3;
	score = 0;

	snakeX[0] = width / 2;
	snakeY[0] = height / 2;
	snakeX[1] = width / 2 - 1;
	snakeY[1] = height / 2;
	snakeX[2] = width / 2 - 2;
	snakeY[2] = height / 2;

	GenerateFood();
}

void ClearScreen() {
	system("cls");
}

void Draw() {
	ClearScreen();

	for (int i=0; i < width+2; i++){
		std::cout << "█";
	}
	std::cout << std::endl;

	for (int i = 0; i < height; i++) {
		std::cout << "█";	// 每行左边框

		for (int j = 0; i < width; j++) {
			if (i == snakeY[0] && j == snakeX[0]) {
				std::cout << "●";  // 头部
			}
			else if (i == foodY && j == foodX) {
				std::cout << "◎";
			}
			else {
				bool isBody = false;
				// 遍历body（从第一节开始，0是head）
				for (int k = 1; k < len; k++) {
					if (snakeX[k] == j && snakeY[k] == i) {
						std::cout << "○";  // body
						isBody = true;
						break;
					}
				}
				if (!isBody) {
					std::cout << " ";  // 空白区域
				}
			}
		}
		std::cout << "█";  // 每行右边框
		std::cout << std::endl;
	}

	for (int i = 0; i < width + 2; i++)
		std::cout << "█";
	std::cout << std::endl;

	// 绘制分数 / 操作信息面板
	std::cout << "╔════════════════════════════════════════════╗" << std::endl;
	std::cout << "║ 长度: " << len;
	std::cout << "  | 分数: " << score * 10;
	std::cout << "  | 方向: ";
}

void Input() {
	if (_kbhit()) {
		char ch = _getch();
		int newDir = -1;
		switch (ch) {
		case 'w': case 'W': newDir = 0; break;
		case 's': case 'S': newDir = 2; break;
		case 'a': case 'A': newDir = 3; break;
		case 'd': case 'D': newDir = 1; break;
		case 'x': case 'X': gameOver = true; return;
		}

		if (newDir != -1 && opposite[dir] != newDir) {
			dir = newDir;
		}
	}
}

void Logic() {
	
}






