///*************************************************************/
///**
// * @file PointerToFunctions_03.c
// * @brief Example 3/3 how pointer to functions are used in PD\n
// *
// * @author Thomas Resch, thomas.resch@campus.tu-berlin.de\n
// *         Markus Hädrich, markus.haedrich@tu-berlin.de
// *
// * @discussion Course: Real-Time Audio Programing in C\n
// * Supervisors: Thomas Resch, Markus Hädrich, (TU-Berlin)\n
// * "Object oriented programming in C - session 02"\n
// *
// * @date 09.05.19. – first implementation
// *
// * @bug if you found one - report it!
// *
// * @version 0.42
// **************************************************************/
//
//
//
//#include <stdio.h>
//#include <stdlib.h>
//
//
///**
// * @typedef @c void pointer to a @c void function.
// */
//typedef void* (*method)(void);
//
///**
// * @typedef @c void pointer to a function, that takes one @c int parameter.
// */
//typedef void* (*methodInt)(int);
//
///**
// * @typedef @c void pointer to a function, that takes two @c int parameter.
// */
//typedef void* (*methodIntInt)(int, int);
//
//
///**
// * @typedef struct with one @c int element only.
// */
//typedef struct oneInt
//{
//    int val1;   /**< Struct @c int variable. */
//} oneInt;
//
//
///**
// * @brief Constructor function that takes a @c int value and returns a pointer\n
// *        to a new @c oneInt struct.
// * @param val1 @c int value of the new struct element
// * @return Pointer to the new struct.
// */
//void *oneInt_new(int val1)
//{
//    oneInt *x = (oneInt *)malloc(sizeof(oneInt));
//    x->val1 = val1;
//    return x;
//}
//
//
///**
// * @typedef struct with two @c int elements.
// */
//typedef struct twoInt
//{
//    int val1;   /**< Struct @c int variable. */
//    int val2;   /**< Struct @c int variable. */
//} twoInt;
//
//
///**
// * @brief Constructor function that takes two @c int values and returns a\n
// * pointer to a new @c twoInt struct.
// * @param val1 @c int value of the new struct element.
// * @param val2 @c int value of the new struct element.
// * @return Pointer to the new struct.
// */
//void *twoInt_new(int val1, int val2)
//{
//    twoInt *x = (twoInt *)malloc(sizeof(twoInt));
//    x->val1 = val1;
//    x->val2 = val2;
//    return x;
//}
//
//
///**
// * @brief Constructor function that takes a pointer to a constructor function\n
// *        and an argument list/count
// * @param args Arguments list used at function call.
// * @param argc Arguments count of argument list used at function call.
// * @return Pointer to the new struct.
// */
//void *intObject_new(method m, int *args, int argc)
//{
//    if(argc == 1)
//    {
//        void* (*new_ptr)(int) = (methodInt) m;
//        return (new_ptr)(args[0]);
//    }
//    
//    else if(argc == 2)
//    {
//        void* (*new_ptr)(int, int) = (methodIntInt) m;
//        return (new_ptr)(args[0], args[1]);
//    }
//    
//    else return NULL;
//    
//}
//
//int main()
//{
//    // Prepare data to pass to to the initializer function.
//    int anArray[1];
//    int anotherArray[2];
//    
//    anArray[0] = 1;
//    anotherArray[0] = 2;
//    anotherArray[1] = 4;
//    
//    // Call init functions of oneInt and twoInt objects.
//    oneInt *a = intObject_new((method)oneInt_new, anArray, 1);
//    twoInt *b = intObject_new((method)twoInt_new, anotherArray, 2);
//    
//    // Print results.
//    printf("%d\n", a->val1);
//    printf("%d %d\n", b->val1, b->val2);
//    
//    return 0;
//}
//
//
