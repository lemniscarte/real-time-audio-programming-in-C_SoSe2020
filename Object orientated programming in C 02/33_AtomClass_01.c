/*************************************************************/
/**
 *  @file AtomClass_01.c
 *  @brief Example how to implement and use a inheritance in PD style
 *  @author Thomas Resch, thomas.resch@campus.tu-berlin.de\n
 *
 *  @discussion Course: Real-Time Audio Programing in C\n
 *  Supervisors: Thomas Resch, Markus Hädrich, (TU-Berlin)\n
 *  "Object oriented programming in C - session 02"
 *
 *  @date 09.05.19. – first implementation
 *
 *  @bug if you found one - report it!
 *
 *  @version 0.42
 **************************************************************/

/*
 Every object in Pure Data must contain the t_object x_obj as its first member.
 This allows for a very basic inheritance mechanism because the memory
 structures are represented exactly as programmed. Therefore functions, that
 only work with the first object member t_object x_obj will work with all
 Pure Data objects.

 
 
 Task:
 
 Write a base class and two derived classes (structs). The base class
 should only contain an integer member type (UNDEFINED, INTEGER or FLOAT as an
 enum). The first derived class (name it for example derivedClassFloat)
 contains also the type and additionally a float value, the second class
 contains the type and an integer value.
 
 Write a function that works on the base class and returns the type.
 
 In the main function create for example a derivedClassFloat value and then
 get its type with the written baseClass_getType() function. You have to cast
 the derived class to the base class.
 */

#include <stdio.h>


/**
 * @brief Enum that is used in an atom struct type.
 * @enum Holds the defined data types of an atom struct type.
 */
enum simpleAtomTypes {UNDEFINED, INTEGER, FLOAT};


/**
 * @brief Base class.
 * @typedef A base class atom object type.
 */
typedef struct baseClass
{
    int type;       /**< @c int variable, that defines the atom type. */
    
} baseClass;


/**
 * @brief Derived class.
 * @typedef A derived class atom object type that owns the base class member.
 */
typedef struct derivedClassFloat
{
    int type;       /**< @c int variable, that defines the atom type. */
    float floatVal; /**< @c float variable of the atom type. */
    
} derivedClassFloat;


/**
 * @brief Derived class.
 * @typedef A derived class atom object type that owns the base class member.
 */
typedef struct derivedClassInt
{
    int type;       /**< @c int variable, that defines the atom type. */
    int intVal;     /**< @c int variable of the atom type. */
    
} derivedClassInt;


/**
 * @brief Function that gets the atom type.
 * @param x Pointer to an atom type object.
 * @return int member of the @c enum @c simpleAtomTypes.
 */
int baseClass_getType(baseClass *x)
{
    return x->type;
}

int main() {
    // Declare a derived class object
    derivedClassFloat someThing;
    
    // Set type and var member
    someThing.type = FLOAT;
    someThing.floatVal = 5.5;
    
    // Get the type of the derived class object using base class casting
    int type = baseClass_getType((baseClass *) &someThing);
    
    // Print the type
    printf("The simple atom type of someThing is ");
    switch (type) {
        case 0:
            printf("UNDEFINED.\n");
            
            break;
        case 1:
            printf("INTEGER.\n");
            
        case 2:
            printf("FLOAT.\n");
            
        default:
            break;
    }
    
    return 0;
}


/*
    Output:
    The simple atom type of someThing is FLOAT.
 */
