/*************************************************************/
/**
 *  @file PureDataExternal.c
 *  @brief Example of a Pure Data External \n
 *
 *  @author IOhannes m zmölnig zmoelnig[AT]iem.at
 *
 *  @discussion Course: Real-Time Audio Programing in C\n
 *  Supervisors: Thomas Resch, Markus Hädrich, (TU-Berlin)\n
 *  "Object oriented programming in C - session 02"\n
 *
 *  And now we now everyting in order to understand the Pure Data external
 *  object structure!
 *
 *
 *  @see https://github.com/pure-data/externals-howto/blob/master/example1/helloworld.c
 *
 **************************************************************/


/** Include the interface to Pd. */
#include "m_pd.h"

/** Define a new "class". */
static t_class *helloworld_class;

/**
 *  @brief This is the dataspace of our new object
 *  @discussion We don't need to store anything, however the first (and only)
 *  entry in this struct is mandatory and of type @c t_object.
 */
typedef struct _helloworld
{
    t_object  x_obj;                /**< Base class only */
} t_helloworld;

/**
 *  @brief This method is called whenever a "bang" is sent to the object
 *  @discussion The name of this function is arbitrary and is registered to
 *  @c Pd in the @c helloworld_setup() routine.
 */
void helloworld_bang(t_helloworld *x)
{
    /*
     * post() is Pd's version of printf()
     * the string (which can be formatted like with printf()) will be
     * output to wherever Pd thinks it has too (pd's console, the stderr...)
     * It automatically adds a newline at the end of the string.
     */
    post("Hello world !!");
}


/**
 *  @brief This is the "constructor" of the class.
 *  @discussion This method is called whenever a new object of this class is
 *  created. The name of this function is arbitrary and is registered to Pd
 *  in the @c helloworld_setup() routine.
 *  @return @c void pointer to the new @c helloworld object.
 */
void *helloworld_new(void)
{
    /*
     * Call the "constructor" of the parent-class
     * this will reserve enough memory to hold "t_helloworld"
     */
    t_helloworld *x = (t_helloworld *)pd_new(helloworld_class);
    
    /*
     * Return the pointer to the class - this is mandatory!
     * If you return "0", then the object-creation will fail.
     */
    return (void *)x;
}


/**
 *  @brief Define the function-space of the class.
 *  @discussion: Within a single-object external the name of this function is
 *  special.
 */
void helloworld_setup(void) {
    // Create a new class.
    helloworld_class = class_new(gensym("helloworld"),          /**< The object's name is "helloworld". */
                                 (t_newmethod)helloworld_new,   /**< The object's constructor is "helloworld_new()". */
                                 0,                             /**< No special destructor. */
                                 sizeof(t_helloworld),          /**< The size of the data-space. */
                                 CLASS_DEFAULT,                 /**< A normal pd object. */
                                 0,                             /**< No creation arguments. */
                                 0);                            /**< Placeholder for something.*/
    /*
     *  Attach functions to messages
     *  Here we bind the "helloworld_bang()" function to the class
     *  "helloworld_class()" - it will be called whenever a bang is received.
     */
    class_addbang(helloworld_class, helloworld_bang);
}





