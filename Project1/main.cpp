# include <iostream>

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

int main() {
	std::cout << Foo::doSomething(4, 3) << std::endl;
}
