// 15_mixed_structs.c

#include <stdio.h>

// Enumeration
typedef enum Filters {
  bq_type_lowpass = 0,
  bq_type_highpass,
  bq_type_bandpass,
  bq_type_notch,
  bq_type_peak,
  bq_type_lowshelf,
  bq_type_highshelf
} filter_t;

// Typedef structure
typedef struct Biquad {
  float fs;   // Sample rate
  float fc;   // Cut off frequency
  float q;    // Quality
  float gain; // Gain for peak and shelving
  float a0;   // Filter parameter
  float a1;   // Filter parameter
  float a2;   // Filter parameter
  float b1;   // Filter parameter
  float b2;   // Filter parameter
  
  enum States {
    active_mode = 0,
    stand_by_mode,
    edit_mode,
	} state;

  filter_t type;
  //enum Filters type;
} biquad_t;     // Define a Biquad type appending "_t"


int main() {
  biquad_t currentFilter;
  currentFilter.state = edit_mode;
  currentFilter.type = bq_type_lowshelf;
  printf("currentFilter.type: %d\n", currentFilter.type);
  printf("currentFilter.state: %d\n", currentFilter.state);

  return 0;
}

/*
Home work:
Expand the 'void printParameters(biquad_t *filter)' from 08_typedefs.c in such a way 
that it also outputs the filter state and the filter type.
*/