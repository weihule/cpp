#include <iostream>
#include <graphics.h>


int main() 
{
	std::cout << "Hello World" << std::endl;
	// 创建一个窗口
	initgraph(640, 480);

	// 画空心圆
	circle(50, 50, 50);
	setfillcolor(GREEN);
	fillcircle(100, 100, 50);
	
	while (1)
	{
	}
	return 0;
}