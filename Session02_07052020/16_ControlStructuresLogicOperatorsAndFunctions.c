//
//  04ControlStructuresLogicOperatorsAndFunctions.c
//  Einführung in C
//
//  Created by mr.markuese on 08.04.19.
//  Copyright © 2019 mr.markuese. All rights reserved.
//


#include <stdio.h>
#include <stdbool.h>

// Global variables
bool sunshine = false;
bool bike_is_broken = true;
bool is_weekend = false;

// Custom data types
typedef enum Activities {
    learn_to_code = 1,
    cycling,
    celebrating,
    tinkering,
    chilling
} activities_t;

// Function declaration
void what_to_do(activities_t x);

int main() {

    activities_t to_do_today;

    // if - else
    if (is_weekend == true) {
        printf("I go into the park.\n");
        to_do_today = chilling;
    } else {
        printf("I go to the programming seminar.\n");
        to_do_today = learn_to_code;
    }

    what_to_do(to_do_today);
    
    if  ((bike_is_broken == true) || (is_weekend == true)) {
        to_do_today = tinkering;
    } else if (is_weekend && !bike_is_broken && sunshine) {
            to_do_today = cycling;
    } else {
        to_do_today = chilling;
    };

    // Function call
    what_to_do(to_do_today);

    // Ternary operator
    (!bike_is_broken) ? (to_do_today = cycling) : (to_do_today = tinkering);

    // Function call
    what_to_do(to_do_today);

    return 0;
}

// Function implementation
void what_to_do(activities_t x) {
    // Switch case
    switch(x) {
        case learn_to_code:
            printf("My activity today: %d learn_to_code\n", x);
            break;
        case cycling:
            printf("My activity today: %d cycling\n", x);
            break;
        case celebrating:
            printf("My activity today: %d celebrating\n", x);
            break;
        case tinkering:
            printf("My activity today: %d tinkering\n", x);
            break;
        case chilling:
            printf("My activity today: %d chilling\n", x);
            break;
        default:
            printf("My activity today: no idea\n");
            break;
    }
}

// Homework: Implement the function "what_to_do" with if-statements only.

