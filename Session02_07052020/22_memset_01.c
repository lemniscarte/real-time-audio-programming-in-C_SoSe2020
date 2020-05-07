//
//  22_memset.c
//  Einführung in C
//
//  Created by mr.markuese on 21.04.19.
//  Copyright © 2019 mr.markuese. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h> // Needed by malloc()
#include <string.h> // Needed by memset()

void fillWithMemset()
{
  char str[50] = "GeeksForGeeks is for programming geeks."; // from geeksforgeeks.org
  printf("\nBefore memset(): %s\n", str);

  // Fill 8 characters starting from str[13] with '.'
  memset(str + 13, '.', 8*sizeof(char));

  printf("After memset():  %s", str);
}

int main() {
    float *p_memory;
    int size = sizeof(float) * 5;
    p_memory = malloc(size);
    
    /* memset() takes value as (any) ASCII! Zero is a special case! */
    memset(p_memory, 0, (size));

    for (int i=0; i<5; i++) {
        printf("memory [%d]: %f\n", i, *(p_memory+i));
    }
    
    fillWithMemset();

    return 0;
}
