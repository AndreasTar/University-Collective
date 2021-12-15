#include <stdio.h>

void func(int *ptr) {
	*ptr = 1;
}

void main() {
	int *p = NULL;
	func(p);
}