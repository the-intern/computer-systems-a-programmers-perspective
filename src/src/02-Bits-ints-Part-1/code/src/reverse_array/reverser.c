#include <stdio.h>

void inplace_swap (int *x, int *y) {
	*y = *x ^ *y;
	*x = *x ^ *y;
	*y = *x ^ *y;
}


void reverse_array (int a[], int cnt) {
	int first, last;

	for (first = 0, last = cnt - 1; first <= last; first++, last--)
		inplace_swap (&a[first], &a[last]);
}
