//
////  04Loops.c
////  Einführung in C
////
////  Created by mr.markuese on 09.04.19.
////  Copyright © 2019 mr.markuese. All rights reserved.
////
//
#include <stdio.h>
#include <math.h>

int main() {

    int length = 5;
    int an_array[length];
    int j = 0;

    // While loop
    while(j < length)               // Condition
    {
        an_array[j] = (int) pow(j,2);
        j++;
    }


    // For loop
    // The scope of i is inside the loop
    for (int i = 0; i < length; i++)    // Condition
    {
        printf("an_array[%d] = %d\n", i, an_array[i]);
    }

    // Do-while loop
    // The scope of i is outside the loop
    // Casting:  (type_name) expression
    int i = ( ( (int)(sizeof(an_array)/sizeof(int)) ) - 1);
    do {
        printf("an_array[%d] = %d\n", i, an_array[i]);
        i--;

    } while (i > 0);                // Condition

    return 0;
}

// Aufgabe: Schreibe ein while-loop analog zur do-while Schleife, dass
// bei length-1 anfängt und bis 0 zählt. Am array-index i soll der Wert
// i*i gespeichert werden. Löse diese mit der pow-funktion. Damit diese
// benutzt werden kann, muss math.h mittels #include hinzugefügt werden.
