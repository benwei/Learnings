#include <iostream>

/*
 * it prints 12 in win-xp + cygwin g++ 4.5.3
 */
struct X {
	int a;
	char b;
	int c;
	void set_value(int v) { a = v; }
	int get_value() { return a; }
	void increase_value() { a++; }
};

int main()
{
	std::cout << sizeof(X) << std::endl;
	return 0;
}
