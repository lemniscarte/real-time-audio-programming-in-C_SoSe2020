#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// Every c program has exact one main() funcuz
int main()
{
    short short_type = 255;      					// declaration and initialization of short type (both in one step)
    int integer_type;           					// declaration of integer type
    integer_type = 1000000;      					// initialization of integer type
    
    float float_type = 0.000001;					// declaration and initialization of float type
    double double_type = 0.000000000000002;			// declaration and initialization of double type
    long double long_double_type = 0.3;				// declaration and initialization of long double type
    
    char char_type = 'c';							// declaration and initialization of char type
    
    bool bool_type = true;        					// declaration and initialization of bool type
													// C99, without #include <stdbool.h>
    
    // Sizeof operator is used to evaluate the size of a variable
    printf("Size of short: %lu bytes\n",sizeof(short_type));
    // SHRT_MIN, SHRT_MAX are macros defined in header limits.h
    printf("Short min: %d, max: %d bytes\n", SHRT_MIN, SHRT_MAX);
    
    printf("Size of int: %ld bytes\n",sizeof(integer_type));
    printf("Size of float: %ld bytes\n",sizeof(float_type));
    printf("Size of double: %ld bytes\n",sizeof(double_type));
    printf("Size of long double: %ld bytes\n",sizeof(long_double_type));
    printf("Size of bool: %ld byte\n",sizeof(bool_type));
    printf("Size of char: %ld byte\n",sizeof(char_type));
    
    return 0;
}

// Aufgabe: Füge printf Anweisungen hinzu, die die Werte der 8 Variablen
// ausgeben. Float Werte können mit %f formatiert werden. Mit %.4f kann die
// Genauigkeit bspw. auf 4 Nachkommastellen beschränkt werden. Bool kann ebenfalls
// mit %d formatiert werden, char entweder mit %c oder %d (vergl. die unterschiedlicheAusgabe)
