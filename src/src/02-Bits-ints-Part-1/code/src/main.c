#include <stdio.h>
#include "reverser.h"

/*
void test_show_bytes (int val);
void test_big_v_little ( );
*/

int main (int argc, char const *argv[]) {
	int even_array[4] = { 1, 2, 3, 4 };
	int odd_array[5] = { 1,2,3,4,5 };

	for (int i = 0; i <= sizeof (even_array); i++) {

		return 0;
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