#include <stdio.h>
#include <limits.h>
#include "byte_rep.h"


int main (int argc, char const *argv[]) {

	short x = 12345;
	short mx = -x;

	int i;
	unsigned u;

	i = 123;
	u = 123;

	int (u);

	/*
	show_bytes ((byte_pointer) &x, sizeof (short));
	show_bytes ((byte_pointer) &mx, sizeof (short));
	*/


	return 0;
}


