#pragma once

// 常量定义
const int width = 160;
const int height = 240;

// 全局变量声明
extern int snakeX[400], snakeY[400];
extern int foodX, foodY;
extern int dir;
extern int len;
extern bool gameOver;
extern int score;

// 函数声明
void Setup();
void Draw();
void Input();
void Logic();
void GameOverScreen();
void ClearScreen();
void GenerateFood();