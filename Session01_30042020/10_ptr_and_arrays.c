// 10_ptr_and_arrays.c

#include <stdio.h>

// Function takes only the start address '*arr' from type 'int' in memory and the length of the array as input parameter
void print_array(int *arr, int length) {
  for (int i=0; i<length; i++) {
    printf("\narray[%d] = %d", i, arr[i]);
	printf("\n*ptr = %d",*arr++);
  }
}

void init_zero_array(int *arr, int len) {
  int i = 0;
  while(i++ < len)
  // Dereference ptr and initialize the value 0 at it's address
  *arr++ = i;
}

int main() {
  int length = 5;
  int an_array[length];
  init_zero_array(&an_array[0], length);

  print_array(an_array, length);

  return 0;
}

/*
Home work:
Rewrite the func 'print_array(int *arr, int length)' using ptr instead of arr[i]
Tip: You can step forward with ptr++.
*/