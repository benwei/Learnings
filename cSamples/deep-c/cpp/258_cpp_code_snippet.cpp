#include <iostream>

/*
 * this program prints 12.
 */

struct X
{
	int a;
	int b;
	int c;
};

int main()
{
	std::cout << "sizeof(X) == " << sizeof(X) << std::endl;
	return 0;
}
