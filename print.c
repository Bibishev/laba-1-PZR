#include "cmdcalc.h"


void print(int result_count, char* decoded_string, int* results, int key) 
{
    printf("Результирующая строка: ");
    for (int i = 0; i < result_count; i++) 
    {
        decoded_string[i] = (char)(results[i] - key);
        printf("%c", decoded_string[i]);
    }
}