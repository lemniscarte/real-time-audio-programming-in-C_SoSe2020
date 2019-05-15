/*************************************************************/
/**
 *  @file LookupTable_03.c
 *  @brief Example 2/3 how to use a lookup table in PD style \n
 *
 *  @author Thomas Resch, thomas.resch@campus.tu-berlin.de\n
 *          Markus Hädrich, markus.haedrich@tu-berlin.de
 *
 *  @discussion Course: Real-Time Audio Programing in C\n
 *  Supervisors: Thomas Resch, Markus Hädrich, (TU-Berlin)\n
 *  "Object oriented programming in C - session 02"\n
 *
 *  @b Task: Now we have to pass the class name together with the object to the \n
 *  @c object_bang() function which is not really necessary. Instead use the \n
 *  described inheritance mechanism and create a base class object which only \n
 *  holds the class name as a @c char array. Add the class name member to both \n
 *  @c structs @c intOne and @c intTwo too.
 *  In the @c newObject() function you store the name argument in the class \n
 *  name member.
 *
 *  @code
 *         typedef void (*bang)(void *);
 *  @endcode
 *
 *  Also implement the bang methods for oneInt & twoInt which should simply \n
 *  print their member values to the command line and attach them to the \n
 *  objects. Instead of calling printf call the bang methods from inside the \n
 *  main function.
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
typedef void* (*method)(void);

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
    method newMethod;
    bling blingMethod;
    int argc;
} registeredIntObject;

/** @typedef struct holding an @c bling object. */
registeredIntObject objectLookupTable[MAXNUMBEROFOBJECTS];
int currentIndex = 0;

typedef struct object
{
    char className[MAXOBJECTNAMESIZE];
} object;

typedef struct oneInt
{
    char className[MAXOBJECTNAMESIZE];
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
    char className[MAXOBJECTNAMESIZE];  /**< @c char array holding class name*/
    int val1;                           /**< class data */
    int val2;                           /**< class data */
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
void registerObject(char *name, method m, int argc)
{
    strcpy(objectLookupTable[currentIndex].name, name);
    objectLookupTable[currentIndex].newMethod = (method)m;
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
 *  @param x Pointer to the given object.
 */
void object_bling(void *x)
{
    // Get the index of the object in the lookup table
    int i = 0;
    while(i<MAXNUMBEROFOBJECTS)
    {
        if(!strcmp(((object *)x)->className, objectLookupTable[i].name))
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
    // Void pointer for holding new object pointer.
    void *x = NULL;
    
    // Get the index of the object in the lookup table.
    int i = 0;
    while(i<MAXNUMBEROFOBJECTS)
    {
        if(!strcmp(name, objectLookupTable[i].name))
            break;
        i++;
    }
    
    // Routines for each case.
    if(objectLookupTable[i].argc == 1)
    {
        // Get the pointer to the matching initializer function.
        void* (*new_ptr)(int) =
        (methodInt) objectLookupTable[i].newMethod;
        
        // Call the initializer via the function pointer.
        x = (new_ptr)(argv[0]);
        strcpy(((object *)x)->className, name);
    }
    
    if(objectLookupTable[i].argc == 2)
    {
        // Get the pointer to the matching initializer function.
        void* (*new_ptr)(int, int) =
        (methodIntInt)objectLookupTable[i].newMethod;
        
        // Call the initializer via the function pointer.
        x = (new_ptr)(argv[0], argv[1]);
        strcpy(((object *)x)->className, name);
    }
    
    // Return pointer to the new object.
    return x;
}




int main()
{
    // Declaration of the Arrays that hold object data.
    int oneElementArray[1];
    int twoElementsArray[2];
    
    // Initialization of the Arrays with object data.
    oneElementArray[0] = 1;
    twoElementsArray[0] = 2;
    twoElementsArray[1] = 4;
    
    // Register objects in the lookup table.
    registerObject("oneint", (method)oneInt_new, 1);
    addBling("oneint", (bling) oneInt_bling);
    registerObject("twoint", (method)twoInt_new, 2);
    addBling("twoint", (bling) twoInt_bling);
    
    // Initialize the new objects
    oneInt *a = newObject("oneint", oneElementArray);
    twoInt *b = newObject("twoint", twoElementsArray);
    
    // Call method that prints the object data to console.
    object_bling(a);
    object_bling(b);
    
    return 0;
}







