/**
 * @file stp_brickwall_pd.c
 * @author Thomas Resch <br>
 * Audiocommunication Group, Technical University Berlin <br>
 * University of Applied Sciences Nordwestschweiz (FHNW), Music-Academy, Research and Development <br>
 * A gain object for pure data <br>
 * <br>
 * @brief A Pure Data gain object for adjusting the volume<br>
 * <br>
 * stp_brickwall~ allows for adjusting the level<br>
 * of any incoming audio signal. <br>
 * <br>
 */

#include "m_pd.h"
#include "stp_brickwall.h"
#include "stp_brickwall_testing.h"

static t_class *stp_brickwall_tilde_class;

/**
 * @struct stp_brickwall_tilde
 * @brief The Pure Data struct of the stp_brickwall~ object. <br>
 * @var stp_brickwall_tilde::x_obj Necessary for every signal object in Pure Data <br>
 * @var stp_brickwall_tilde::f Also necessary for signal objects, float dummy dataspace <br>
 * for converting a float to signal if no signal is connected (CLASS_MAINSIGNALIN) <br>
 * @var stp_brickwall_tilde::gain The gain object for the actual signal processing <br>
 * @var stp_brickwall_tilde::x_out A signal outlet for the adjusted signal
 * level of the incoming signal
 */

typedef struct stp_brickwall_tilde
{
    t_object  x_obj;
    t_sample f;
    stp_brickwall *brickwall;
    t_outlet*x_out;
} stp_brickwall_tilde;

/**
 * @related stp_brickwall_tilde
 * @brief Calculates the volume adjusted output vector<br>
 * @param w A pointer to the object, input and output vectors. <br>
 * For more information please refer to the Pure Data Docs <br>
 * The function calls the stp_brickwall_perform method. <br>
 * @return A pointer to the signal chain right behind the stp_brickwall_tilde object. <br>
 */

t_int *stp_brickwall_tilde_perform(t_int *w)
{
    stp_brickwall_tilde *x = (stp_brickwall_tilde *)(w[1]);
    t_sample  *in = (t_sample *)(w[2]);
    t_sample  *out =  (t_sample *)(w[3]);
    int n =  (int)(w[4]);

    stp_brickwall_perform(x->brickwall, in, out, n);

    /* return a pointer to the dataspace for the next dsp-object */
    return (w+5);
}

/**
 * @related stp_brickwall_tilde
 * @brief Adds stp_brickwall_tilde_perform to the signal chain. <br>
 * @param x A pointer the stp_brickwall_tilde object <br>
 * @param sp A pointer the input and output vectors <br>
 * For more information please refer to the <a href = "https://github.com/pure-data/externals-howto" > Pure Data Docs </a> <br>
 */

void stp_brickwall_tilde_dsp(stp_brickwall_tilde *x, t_signal **sp)
{
    dsp_add(stp_brickwall_tilde_perform, 4, x, sp[0]->s_vec, sp[1]->s_vec, sp[0]->s_n);
}

/**
 * @related stp_brickwall_tilde
 * @brief Frees our object. <br>
 * @param x A pointer the stp_brickwall_tilde object <br>
 * For more information please refer to the <a href = "https://github.com/pure-data/externals-howto" > Pure Data Docs </a> <br>
 */

void stp_brickwall_tilde_free(stp_brickwall_tilde *x)
{
    outlet_free(x->x_out);
    stp_brickwall_free(x->brickwall);
}

/**
 * @related stp_brickwall_tilde
 * @brief Creates a new stp_brickwall_tilde object.<br>
 * @param f Sets the initial gain value. <br>
 * For more information please refer to the <a href = "https://github.com/pure-data/externals-howto" > Pure Data Docs </a> <br>
 */

void *stp_brickwall_tilde_new(t_floatarg makeUpLevel, t_floatarg clippingLevel)
{
    stp_brickwall_tilde *x = (stp_brickwall_tilde *)pd_new(stp_brickwall_tilde_class);
    
    //The main inlet is created automatically
    x->x_out = outlet_new(&x->x_obj, &s_signal);
    x->brickwall = stp_brickwall_new();
    x->brickwall->makeUpLevel = makeUpLevel;
    x->brickwall->clippingLevel = clippingLevel;

    return (void *)x;
}

/**
 * @related stp_brickwall_tilde
 * @brief Sets the gain adjustment parameter. <br>
 * @param x A pointer the stp_brickwall_tilde object <br>
 * @param level Sets the level parameter <br>
 * For more information please refer to the <a href = "https://github.com/pure-data/externals-howto" > Pure Data Docs </a> <br>
 */

void stp_brickwall_tilde_setMakeUpLevel(stp_brickwall_tilde *x, float makeUpLevel)
{
    stp_brickwall_setMakeUpLevel(x->brickwall, makeUpLevel);
}

/**
 * @related stp_brickwall_tilde
 * @brief Sets the clipping level parameter. <br>
 * @param x A pointer the stp_brickwall_tilde object <br>
 * @param makeUpLevel Sets the makeUpLevel parameter <br>
 */

void stp_brickwall_tilde_setClippingLevel(stp_brickwall_tilde *x, float clippingLevel)
{
    stp_brickwall_setClippingLevel(x->brickwall, clippingLevel);
}

/**
 * @related stp_brickwall_tilde
 * @brief Sets the clipping level parameter. <br>
 * @param x A pointer the stp_brickwall_tilde object <br>
 * @param makeUpLevel Sets the makeUpLevel parameter <br>
 */

void stp_brickwall_tilde_integrationTest(stp_brickwall_tilde *x)
{
    stp_brickwallTest *test = stp_brickwallTest_new(x->brickwall, 32, 64);
    stp_brickwallTest_integration(test);
    stp_brickwallTest_free(test);
}

/**
 * @related stp_brickwall_tilde
 * @brief Setup of stp_brickwall_tilde <br>
 * For more information please refer to the <a href = "https://github.com/pure-data/externals-howto" > Pure Data Docs </a> <br>
 */

void stp_brickwall_tilde_setup(void)
{
      stp_brickwall_tilde_class = class_new(gensym("stp_brickwall~"), (t_newmethod)stp_brickwall_tilde_new, (t_method)stp_brickwall_tilde_free,
                                            sizeof(stp_brickwall_tilde), CLASS_DEFAULT, A_DEFFLOAT, A_DEFFLOAT, 0);

      class_addmethod(stp_brickwall_tilde_class, (t_method)stp_brickwall_tilde_dsp, gensym("dsp"), 0);
      class_addmethod(stp_brickwall_tilde_class, (t_method)stp_brickwall_tilde_setMakeUpLevel, gensym("makeuplevel"), A_DEFFLOAT, 0);
      class_addmethod(stp_brickwall_tilde_class, (t_method)stp_brickwall_tilde_setClippingLevel, gensym("clippinglevel"), A_DEFFLOAT, 0);
      class_addmethod(stp_brickwall_tilde_class, (t_method)stp_brickwall_tilde_integrationTest, gensym("integrationtest"), 0);
      CLASS_MAINSIGNALIN(stp_brickwall_tilde_class, stp_brickwall_tilde, f);
}
