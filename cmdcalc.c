#include "cmdcalc.h"

int calculate(int a, char operator, int b) 
{
    switch (operator) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '%':
        if (b == 0) 
        {
            printf("Ошибка: деление на 0\n");
            exit(1);
        }
        return a % b;
    default:
        printf("Ошибка: некорректный оператор '%c'\n", operator);
        exit(1);
    }
}