#include <iostream>
#include <graphics.h>


int main() 
{
	std::cout << "Hello World" << std::endl;
	// ����һ������
	initgraph(640, 480);

	// ������Բ
	circle(50, 50, 50);
	setfillcolor(GREEN);
	fillcircle(100, 100, 50);
	
	while (1)
	{
	}
	return 0;
}