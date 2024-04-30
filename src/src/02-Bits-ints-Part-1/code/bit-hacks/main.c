#include <stdio.h>
#include <string.h>

void inplace_swap (char *x, char *y) {
	*y = *x ^ *y;
	*x = *x ^ *y;
	*y = *x ^ *y;
}


void reverse_array (char *a, int cnt) {
	int first, last;

	for (first = 0, last = cnt - 1; first <= last; first++, last--)
		inplace_swap (&a[first], &a[last]);
}


void play ( ) {
	char *s;
	s = "0b0010";
	for (int i = sizeof (s) - 1; i >= 0; i--) {
		if (s[i] == 'b') {
			break;
		}
		printf ("%c\n", s[i]);
	}
}

void printBinary (unsigned int num) {
	if (num > 1)
		printBinary (num / 2);
	printf ("%d", num % 2);
}
void setToOne (unsigned int num) {
	printf ("Original number = %d: 0b", num);
	printBinary (num);
	printf ("\n");
	num = (1 << 2) | num;
	printf ("Bitwise change to number = %d: 0b", num);
	printBinary (num);
	printf ("\n");

}

/* Determine whether string s is longer than string t
WARNING : This function is buggy • /
*/
int strlonger (char *s, char *t) {
	int res = strlen (s) - strlen (t);
	printf ("Result = %d\n\n", res);
	return res > 0;
}

int main (int argc, char const *argv[]) {
	char *s = "";
	char *t = "123";
	int res = strlonger (s, t);
	printf ("----------\n");
	printf ("Whether ==> ");
	printf ("%d\n", res);
	if (res == 1) printf ("True\n");
	if (res == 0) printf ("False\n");
	printf ("----------\n");

	size_t ls = strlen (s);
	size_t lt = strlen (t);
	printf ("\nThe length of s = %zu, that of t = %zu\n", ls, lt);

}
