// 08_pointers.c

#include <stdio.h>


int main()
{
    int *cPtr;
    int c;

    c = 22;
    printf("Address of c: %p\n", &c);
    printf("Value of c: %d\n\n", c);

    cPtr = &c;
    printf("Address of pointer pc: %p\n", cPtr);
    printf("Content of pointer pc: %d\n\n", *cPtr);

    c = 11;
    printf("Value of pointer pc: %d\n\n", *cPtr);

    *cPtr = 2;
    printf("Address of c: %p\n", &c);
    printf("Value of c: %d\n\n", c);


    return 0;
}

/*
Home work:
Read about "Call by value" and "Call by reference" in your favorite C programming book and explain the difference!
*/