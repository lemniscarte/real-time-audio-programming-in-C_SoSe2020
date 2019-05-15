///*************************************************************/
///**
// *  @file PointerToFunctions_01.c
// *  @brief Example 1/3 how pointer to functions are used in PD\n
// *
// *  @author Thomas Resch, thomas.resch@campus.tu-berlin.de\n
// *          Markus Hädrich, markus.haedrich@tu-berlin.de
// *
// *  @discussion Course: Real-Time Audio Programing in C\n
// *  Supervisors: Thomas Resch, Markus Hädrich, (TU-Berlin)\n
// *  "Object oriented programming in C - session 02"\n\n
// *
// *  To provide an SDK for external objects, Pure Data implements a tricky class
// *  register mechanism. Within the object setup function (which is called on
// *  Pure Data's startup), @c class_new() is called. Arguments are the object’s
// *  name, its new function, its free function, its size, its type and the type
// *  of arguments it expects. @C class_new returns a pointer which is stored in
// *  a global pointer.
// *
// *  @code
// *          static t_class *helloworld_class;
// *
// *          void helloworld_setup(void) {
// *               helloworld_class = class_new(gensym("helloworld"),
// *                                           (t_newmethod)helloworld_new,
// *                                           0,
// *                                           sizeof(t_helloworld),
// *                                           CLASS_DEFAULT,
// *                                           0);
// *
// *          class_addbang(helloworld_class, helloworld_bang);
// *          }
// *  @endcode
// *
// *  @date 09.05.19. – first implementation
// *
// *  @bug if you found one - report it!
// *
// *  @version 0.42
// **************************************************************/
//
//
//
///*
// *   What we haven’t seen so far is passing a function name as an argument to
// *   another function. In this case the helloworld_new() function
// *
// *   The syntax for this dealing with function pointers is shown in the
// *   following examples.
// */
//
//
//#include <stdio.h>
//
///**
// * @brief Function that prints a value.
// * @param a Value to print.
// */
//void fun(int a) {
//    printf("Value of a is %d\n", a);
//}
//
//int main()
//{
//    // void pointer to the function fun.
//    void (*fun_ptr)(int) = &fun;
//    
//    // Call the function fun via passing a value to the function pointer
//    (*fun_ptr)(10);
//    
//    return 0;
//}
