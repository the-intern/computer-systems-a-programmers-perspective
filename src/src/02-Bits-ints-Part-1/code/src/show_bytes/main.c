#include <stdio.h>
#include "reverser.h"

/*
void test_show_bytes (int val);
void test_big_v_little ( );
*/

void inplace_swap (int *x, int *y);
void reverse_array (int a[], int cnt);
void phelper (int first, int last, int cnt, int ar[]);

int main (int argc, char const *argv[]) {
	// int even_array[4] = { 1, 2, 3, 4 };
	int odd_array[5] = { 1, 2, 3, 4, 5 };

	// for (int i = 0; i < 4; i++) {
	// 	printf ("%d\n", odd_array[i]);
	// }

	printf ("\n---------------------\n");
	reverse_array (odd_array, 5);

	for (int i = 0; i < 4; i++) {
		printf ("%d\n", odd_array[i]);
	}


	return 0;
}

// ! use these for now
void inplace_swap (int *x, int *y) {
	*y = *x ^ *y;
	*x = *x ^ *y;
	*y = *x ^ *y;
}


void reverse_array (int a[], int cnt) {
	int first, last;
	for (first = 0, last = cnt - 1; first < last; first++, last--) {
		phelper (first, last, cnt, a);
		inplace_swap (&a[first], &a[last]);
	}
}

void phelper (int first, int last, int cnt, int ar[]) {
	// printf ("first = %d\n", first);
	// printf ("last = %d\n", last);
	// printf ("cnt = %d\n", cnt);
	// printf ("---- array ----\n");
	// for (int i = 0; i < 5; i++) {
	// 	printf ("Array [%d] = %d\n", i, ar[i]);
	// }

}

/*
void test_big_v_little ( ) {
	int val = 0x87654321;
	byte_pointer valp = (byte_pointer) &val;
	show_bytes (valp, 1);
	show_bytes (valp, 2);
	show_bytes (valp, 3);
}

void test_show_bytes (int val) {
	int ival = val;
	float fval = (float) ival;
	int *pval = &ival;
	show_int (ival);
	show_float (fval);
	show_pointer (pval);
}

*/