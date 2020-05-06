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

int main() {
    float *p_memory;
    int size = sizeof(float) * 5;
    p_memory = malloc(size);
    
    /* memset() takes value as (any) ASCII! Zero is a special case! */
    memset(p_memory, 0, (size));

    for (int i=0; i<5; i++) {
        printf("memory [%d]: %f\n", i, *(p_memory+i));
    }

    return 0;
}
