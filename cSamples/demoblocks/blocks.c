#include <Block.h>
#include <stdio.h>

// define block
typedef int (^IntBlock)();

// In mathematics, an arithmetic progression (AP) or arithmetic sequence is a sequence of
// numbers such that the difference of any two successive members of the sequence is a constant. For instance, the sequence 3, 5, 7, 9, 11, 13,
// it is an arithmetic progression with common difference 2.

IntBlock mathAP(int firstTerm, int difference) {
	__block int  computeTerm = firstTerm;
	
	return Block_copy( ^ {
		computeTerm += difference;
		return computeTerm;
	});
}

int mathAPloop(int n, IntBlock blockAP)
{
	int m = n;
	while (n-- > 0) {
		printf("a%d: %d\n", m - n, blockAP());
	}
	
	return 0;
}

int main() {
	
	IntBlock blockAP = mathAP(1, 3);
	
	mathAPloop(10, blockAP);
	
	Block_release(blockAP);
	return 0;
}
