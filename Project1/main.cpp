# include <iostream>
# include <string>

namespace Foo {
	int doSomething(int x, int y) {
		return x + y;
	}
}

namespace Goo {
	int doSomething(int x, int y) {
		return x - y;
	}
}

int getValue() {
	std::cout << "Enter: ";
	int x{};
	std::cin >> x;
	return x;
}

void printByValue(std::string val) {
	std::cout << val << std::endl;
}

int main() {
	int x{ 5 };
	int& ref{ x };
	std::cout << "ref=" << ref << " x=" << x << std::endl;

	x = 6;
	std::cout << "ref=" << ref << " x=" << x << std::endl;

	std::cout << "&ref=" << &ref << " &x=" << &x << " *(&x)= " << *(&x) << std::endl;
}
