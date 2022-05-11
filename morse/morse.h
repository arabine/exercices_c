#ifndef MORSE_H
#define MORSE_H

#include <stdbool.h>

#define MAX_INPUT_STRING    64
#define MAX_OUTPUT_STRING   ((5*3 + 4 + (MAX_INPUT_STRING/2 - 1) * 7))

/**
 * @brief Transform a text intput into morse
 * 
 * User must provide output buffer of 
 * 
 * @arg input: char string
 * @arg output: char morse
 */
bool encode(const char *input, char *output);


#endif // MORSE_H
