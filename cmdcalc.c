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
            printf("������: ������� �� 0\n");
            exit(1);
        }
        return a % b;
    default:
        printf("������: ������������ �������� '%c'\n", operator);
        exit(1);
    }
}