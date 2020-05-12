// Swapping pointers vs. swapping values
 
#include <stdio.h>
#include <stdlib.h>

void swap_two_ptrs(int** a, int** b) {
	int *temp = *a;
	*a = *b;
	*b = temp;
}

void swap_two_values(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	// Init some data
	int x, y, *a, *b;
	x = 42;
	y = 84;
	// Write the memory place of the data into the ptrs
	a = &x;
	b = &y;
	// Print the data by dereferencing the ptrs
	printf("*a = %d\t(in memory: %p)\n", *a, a);
	printf("*b = %d\t(in memory: %p)\n", *b, b);
	// Call swap func
	printf("\n\nSwap pointers:\n");
	swap_two_ptrs(&a, &b);
	// Print the data by dereferencing the ptrs again
	printf("*a = %d\t(in memory: %p)\n", *a, a);
	printf("*b = %d\t(in memory: %p)\n", *b, b);
	// Check the result
	printf("Result:\nx: %d\ny: %d\n*a: %d\n*b: %d\n", x, y, *a, *b);
	if (*b == x && *a == y) {
		printf("Pointers swapped!\n");
	} else {
		printf("Pointers not swapped!\n");
	}
	
	printf("\n------------------------------------\n\n");
	x = 42;
	y = 84;
	// Write the memory place of the data into the ptrs
	a = &x;
	b = &y;
	// Print the data by dereferencing the ptrs
	printf("*a = %d\t(in memory: %p)\n", *a, a);
	printf("*b = %d\t(in memory: %p)\n", *b, b);
	// Call swap func
	printf("\n\nSwap values:\n");
	swap_two_values(a, b);
	// Print the data by dereferencing the ptrs again
	printf("*a = %d\t(in memory: %p)\n", *a, a);
	printf("*b = %d\t(in memory: %p)\n", *b, b);
	// Check the result
	printf("Result:\nx: %d\ny: %d\n*a: %d\n*b: %d\n", x, y, *a, *b);
	if (*b == x && *a == y) {
		printf("Pointers swapped!\n");
	} else {
		printf("Pointers not swapped!\n");
	}
	
}