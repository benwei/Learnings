#include <stdio.h>
#include "Block.h"
typedef int(^ablock)(void);

ablock dosth(int difference)
{
	__block int a = 1;
	int b = difference;

	return Block_copy(^{
		a += b;
		return a;
	});
}

int main()
{
	ablock a = dosth(10);
	int i;
	for (i = 0 ; i < 3; i++) {
		printf("%d\n", a());
	}
	Block_release(a);
	return 0;
}
