//
//  22_Realloc.c
//  Einführung in C
//
//  Created by mr.markuese on 15.04.19.
//  Copyright © 2019 mr.markuese. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr, n1, n2;
    printf("Enter size of array: ");
    scanf("%d", &n1);
    
    ptr = (int*) malloc(n1 * sizeof(int));
    
    printf("Addresses of previously allocated memory: ");
    for(int i = 0; i < n1; i++)
        printf("%p\n",ptr + i);
    
    printf("\nEnter new size of array: ");
    scanf("%d", &n2);
    ptr = realloc(ptr, n2 * sizeof(int));
    
    printf("Addresses of newly allocated memory: ");
    for(int i = 0; i < n2; i++)
        printf("%p\n", ptr + i);
    
    
    free(ptr);
    
    return 0;
}
