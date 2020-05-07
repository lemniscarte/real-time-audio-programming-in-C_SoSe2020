//
//  17_Malloc.c
//  Einführung in C
//
//  Created by mr.markuese on 10.04.19.
//  Copyright © 2019 mr.markuese. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n, i, *ptr, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));

    // Before writing to the memory
    for (int i=0; i<n; i++) {
        printf("memory initialized with %d\n", *(ptr+n));
    }

    // Error handling
    if(ptr == NULL) {
        printf("Error! memory not allocated.");
        exit(0);
    }

    printf("Enter elements: \n");
    for(i = 0; i < n; ++i) {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    printf("Sum = %d\n", sum);

    // After writing to the memory
    for (int i=0; i<n; i++) {
        printf("value in memory: %d\n", *(ptr+i));
    }

    printf("%p",ptr);
    free(ptr);
   
    


    return 0;
}


