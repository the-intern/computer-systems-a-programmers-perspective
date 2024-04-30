#include <stdio.h>
#include <string.h>

/*
Include Headers: We include stdio.h for input/output functions and string.h for string manipulation functions like strlen.

	reverseArray Function:

		Takes a character array arr and its size size as input.

		Uses a loop to iterate through half of the array (up to size / 2).

		Inside the loop, it swaps the character at index i with the character at index size - 1 - i, effectively reversing the order.

	main Function:

		Declares a character array str to hold the input string.

		Prompts the user to enter a string using printf.

		Reads the input string using fgets to include spaces. fgets stores the newline character (\n) at the end of the input.

		Removes the trailing newline character using strchr to find its position and replacing it with a null terminator (\0).

		Calculates the length of the string using strlen.

		Calls the reverseArray function to reverse the characters in str.

		Prints the reversed string using printf.

To use the function:

	Compile the code into an executable.

	Run the executable.

	Enter a string when prompted.

	The program will display the reversed string.

*/

void reverseArray (char arr[], int size) {
	for (int i = 0; i < size / 2; i++) {
		char temp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp;
	}
}

int result ( ) {
	char str[100];
	printf ("Enter a string: ");
	fgets (str, 100, stdin);  // Read input including spaces

	// Remove trailing newline, if present
	str[strchr (str, '\n') - str] = '\0';

	int len = strlen (str);
	reverseArray (str, len);

	printf ("Reversed string: %s\n", str);

	return 0;
}