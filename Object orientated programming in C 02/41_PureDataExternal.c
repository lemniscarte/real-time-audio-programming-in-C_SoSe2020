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

#include "m_pd.h"

static t_class *helloworld_class;

typedef struct _helloworld
{
    t_object  x_obj;
} t_helloworld;

void helloworld_bang(t_helloworld *x)
{
    post("Hello world !!");
}

void *helloworld_new(void)
{
    return (void *)x;
}

void helloworld_setup(void) {
    helloworld_class = class_new(gensym("helloworld"),
                                 (t_newmethod)helloworld_new,
                                 0,
                                 sizeof(t_helloworld),
                                 CLASS_DEFAULT,
                                 0);
    
    class_addbang(helloworld_class, helloworld_bang);
}





