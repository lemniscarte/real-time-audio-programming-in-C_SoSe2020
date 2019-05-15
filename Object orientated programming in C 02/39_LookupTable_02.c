/*************************************************************/
/**
 *  @file LookupTable_02.c
 *  @brief Example 2/3 of pointer to functions in a lookup table\n
 *
 *  @author Thomas Resch, thomas.resch@campus.tu-berlin.de\n
 *          Markus Hädrich, markus.haedrich@tu-berlin.de
 *
 *  @discussion Course: Real-Time Audio Programing in C\n
 *  Supervisors: Thomas Resch, Markus Hädrich, (TU-Berlin)\n
 *  "Object oriented programming in C - session 02"\n
 *
 *  @b Task: Add a member for a bling method to the @c registeredObject @c struct \n
 *  and a function for adding the bling method. Our bling method does not return \n
 *  anything and gets its instance as void pointer.
 *
 *  @code
 *         typedef void (*bling)(void *);
 *  @endcode
 *
 *  Also implement the bling methods for @c oneInt & @c twoInt which should \n
 *  simply print their member values to the command line and attach them to \n
 *  the objects. Instead of calling @c printf call the bling methods from \n
 *  inside the main function.
 *
 *  @date 09.05.19. – first implementation
 *
 *  @bug if you found one - report it!
 *
 *  @version 0.42
 **************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** @const Number + 1 chars that can be used to name the object type */
#define MAXOBJECTNAMESIZE 24

/** @const Number of objects that can be created */
#define MAXNUMBEROFOBJECTS 10

/** @typedef @c void pointer to a @c void function. */
typedef void* (*new)(void);

/** @typedef @c void pointer to a function, that takes one @c int parameter. */
typedef void* (*methodInt)(int);

/** @typedef @c void pointer to a function, that takes two @c int parameter. */
typedef void* (*methodIntInt)(int, int);


/** @typedef @c void function, that takes a function pointer */
typedef void (*bling)(void *);


/** @typedef struct holding an @c bling object. */
typedef struct registeredIntObject
{
    char name[MAXOBJECTNAMESIZE];
    new newMethod;              /**< Initializer method. */
    bling blingMethod;          /**< Just a name for a method. */
    int argc;                   /**< Index count in the lookup table. */
} registeredIntObject;


/** @brief Lookup table for your objects. */
registeredIntObject objectLookupTable[MAXNUMBEROFOBJECTS];
int currentIndex = 0;


/** @typedef struct with one @c int element only. */
typedef struct oneInt
{
    int val1;
} oneInt;


/**
 *  @brief Constructor function that takes a @c int value and returns a pointer\n
 *  to a new @c oneInt struct.
 *  @param v1 @c int value of the new struct element.
 *  @return x Pointer to the new @c oneInt object.
 */
void *oneInt_new(int v1)
{
    oneInt *x = (oneInt *)malloc(sizeof(oneInt));
    x->val1 = v1;
    return x;
}

/**
 *  @brief Method to print the data of a @c oneInt object.
 *  @param x @c void pointer to an @c oneInt object.
 */
void oneInt_bling(void *x)
{
    printf("%d\n", ((oneInt *)x)->val1);
}


/** @typedef struct with two @c int elements. */
typedef struct twoInt
{
    int val1;
    int val2;
} twoInt;


/**
 *  @brief Constructor function for a @c twoInt object, that takes two @c int\n
 *  values and returns a pointer to a new @c oneInt struct object.
 *  @param v1 @c int value of the new struct element.
 *  @param v2 @c int value of the new struct element.
 *  @return x Pointer to the new @c oneInt object.
 */
void *twoInt_new(int v1, int v2)
{
    twoInt *x = (twoInt *)malloc(sizeof(twoInt));
    x->val1 = v1;
    x->val2 = v2;
    return x;
}


/**
 *  @brief Method to print the data of a @c twoInt object.
 *  @param x @c void pointer to an @c twoInt object.
 */
void twoInt_bling(void *x)
{
    printf("%d, %d\n", ((twoInt *)x)->val1, ((twoInt *)x)->val2);
}


/**
 *  @brief Function to register an object in the lookup table
 *  @param name @c char pointer to an array with the object name.
 *  @param m Method to initialize the new object.
 *  @param argc Lookup table index as arguments count.
 */
void registerObject(char *name, new m, int argc)
{
    strcpy(objectLookupTable[currentIndex].name, name);
    objectLookupTable[currentIndex].newMethod = (new)m;
    objectLookupTable[currentIndex].argc = argc;
    currentIndex++;
}


/**
 *  @brief Function to add a method of an object to the lookup table.
 *  @param name @c char pointer to an array with the object name.
 *  @param b Method of the object.
 */
void addBling(char *name, bling b)
{
    // Get the index of the object in the lookup table
    int i = 0;
    while(i<MAXNUMBEROFOBJECTS)
    {
        if(!strcmp(name, objectLookupTable[i].name))
            break;

        i++;
    }

    // Add the method to the object
    objectLookupTable[i].blingMethod = b;
}


/**
 *  @brief Function that calls the @c blingMethod of a given object.
 *  @param name @c char pointer to an array with the object name.
 *  @param x Pointer to the given object.
 */
void object_bling(char *name, void *x)
{
    // Get the index of the object in the lookup table
    int i = 0;
    while(i<MAXNUMBEROFOBJECTS)
    {
        if(!strcmp(name, objectLookupTable[i].name))
            break;
        i++;
    }

    // Call the @c blingMethod of the object pointed by @c x 
    (objectLookupTable[i].blingMethod)(x);
}



/**
 *  @brief General initializer function.
 *  @param name @c char pointer to an array with the object name.
 *  @param argv Pointer to the arguments array (argument vector).
 *  @return Pointer to the new object.
 */
void *newObject(char *name, int *argv)
{
    // Get the index of the object in the lookup table
    int i = 0;
    while (i<MAXNUMBEROFOBJECTS)
    {
        if(!strcmp(name, objectLookupTable[i].name))
            break;
        i++;
    }

    // Routines for each case
    if (objectLookupTable[i].argc == 1)
    {
        // Get the pointer to the matching initializer function.
        void* (*new_ptr)(int) =
        (methodInt)objectLookupTable[i].newMethod;

        // Call the initializer via the function pointer.
        return (new_ptr)(argv[0]);
    }

    else if (objectLookupTable[i].argc == 2)
    {
        // Get the pointer to the matching initializer function.
        void* (*new_ptr)(int, int) =
        (methodIntInt)objectLookupTable[i].newMethod;

        // Call the initializer via the function pointer.
        return (new_ptr)(argv[0], argv[1]);
    }

    else return NULL;
}





int main()
{
    // Imitation of setup in PD style
    // ==============================
    
    // Declaration of the Arrays that hold object data.
    int oneElementArray[1];
    int twoElementsArray[2];

    // Initialization of the Arrays with object data.
    oneElementArray[0] = 1;
    twoElementsArray[0] = 2;
    twoElementsArray[1] = 4;

    // Register objects in the lookup table.
    registerObject("oneint", (new)oneInt_new, 1);
    addBling("oneint", (bling) oneInt_bling);
    registerObject("twoint", (new)twoInt_new, 2);
    addBling("twoint", (bling) twoInt_bling);

    
    
    // Imitation of new in PD style
    // ============================
    
    // Initialize the new objects
    oneInt *a = (*oneint)newObject("oneint", oneElementArray);
    twoInt *b = (*twoInt)newObject("twoint", twoElementsArray);

    // Print objects data to console.
    object_bling("oneint", a);
    object_bling("twoint", b);

    return 0;
}








/*
 *  Output:
 *      1
 *      2, 4
 */
