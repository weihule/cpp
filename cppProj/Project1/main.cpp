#include <iostream>
#include <string>

int main()
{
	std::cout << "Hello World" << std::endl;

	int res = 0;
	for (int i = 0; i < 10; i++)
	{
		res += i;
	}

	std::cout << "res = " << res << std::endl;
}
