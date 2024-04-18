#include <stdio.h>
#include <math.h>
#include <limits.h>

/*
bis (bit set) and bic (bit clear).

Both instructions take a data word x and a mask word m. They generate a result z consisting of the bits of x modified according to the bits of m.
With bis, the modification involves setting z to 1 at each bit position where m is 1.
With bic, the modification involves setting z to 0 at each bit position where m is 1.

*/

int bis (int x, int m);
int bic (int x, int m);
int remainder_quotient ( );
int convert (int x);

int main (int argc, char const *argv[]) {

	char uc;
	uc = 120;
	printf ("uc = %c\n");



	return 0;
}

int bis (int x, int m) {
	int notx = ~x;
	int z = notx | m;
	return z;
}

int bic (int x, int m) {
	return 0;
}

int convert (int decimal_num) {
	int binary_num = 0, i = 1, remainder;

	while (decimal_num != 0) {
		remainder = decimal_num % 2;
		decimal_num /= 2;
		binary_num += remainder * i;
		i *= 10;
	}
	return binary_num;
}


int remainder_quotient ( ) {
	int dividend, divisor, remainder, quotient;
	dividend = 11;
	divisor = 2;
	remainder = dividend % divisor;
	quotient = dividend / divisor;

	printf ("%d %d %d\n", quotient, remainder, quotient * divisor + remainder == dividend);

	return 0;
}