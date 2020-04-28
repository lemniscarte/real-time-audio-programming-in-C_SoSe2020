// 09_ptr_as_func_param.c

#include <stdio.h>

// --- Example 01 ----
int i = 4;
int* iPtr = &i;

int func_call_by_value(int x) {
 	 return x + 5;
}


int* func_call_by_reference(int *x) {
	*x = *x + 5;
  	return x;
}



// --- Example 02 ----
int addTwoIntegers(int *x, int *y) {
	int z = *x + *y;
   	return z;
}


int main() {
	printf("\n--- Example 01 ----\n");
	// Work with a copy of i
	printf("%d\n", func_call_by_value(i));
	// Overwrite the value of i
	printf("%d\n", *func_call_by_reference(iPtr));
	// New value stored in i
	printf("%d\n", i);


	printf("\n--- Example 02 ----\n");
	// Declaration
	int x, y;
	// Initialization
	x = 1; y = 3;
	// Addresses == pointers, &x == *xPtr
	int *xPtr = &x;
	printf("The pointer points to the address of the var:\n");
	printf("xPtr = %p, &x = %p\n", xPtr, &x);
	printf("\nThe dereferenced pointer points to the value of the var:\n");
	printf("*xPtr = %d, x = %d\n", *xPtr, x);
	
	int result = addTwoIntegers(&x, &y);
	printf("\nThe result ist %d\n", result);

	return 0;
}