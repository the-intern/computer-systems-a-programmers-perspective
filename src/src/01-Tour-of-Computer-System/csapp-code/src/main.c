#include <stdio.h>

#include "byte_rep.h"

void test_show_bytes (int val);
void test_big_v_little ( );

int main (int argc, char const *argv[]) {
	// test_show_bytes (23456);
	test_big_v_little ( );

	return 0;
}
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
