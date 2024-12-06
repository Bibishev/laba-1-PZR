#ifndef CMDCALC_H
#define CMDCALC_H  


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int calculate(int a, char operator, int b);
void print(int result_count, char* decoded_string, int* results, int key);

#endif