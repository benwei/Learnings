#include <iostream>
/* It looks weired to specify func(void) instead of func() as void is the
 * default in C++. It just looks like the code is written by a die-hard C
 * programmer struggling to learn C++
 */

struct X
{
	int a;
	int b;
	int c;
};

int main(void)
{
	std::cout << "sizeof(X) == " << sizeof(X) << std::endl;
	return 0;
}
