#include<stdio.h>

int * immortal(void){	
	static int storage = 42;	
	return &storage;
}

int main(void)
{
    printf("%p\n", immortal());
    return 0;
}
