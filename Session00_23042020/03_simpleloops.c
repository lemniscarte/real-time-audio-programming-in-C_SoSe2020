#include <stdio.h>

int main(void) {

    int length = 5;
    int anArray[length];
    int i = 0;

    while(i < length)
    {
        anArray[i] = i;
        printf("%d %d\n", i, anArray[i]);
        i++;
    }


    for(i = 0; i < length; i++)
    {
        anArray[i] = i;
        printf("%d %d\n", i, anArray[i]);
    }

    return 0;
}

// Aufgabe: Schreibe eine while- und eine for-Schleife, die in das
// Array am index i den Wert length - i speichert und ausgibt.
