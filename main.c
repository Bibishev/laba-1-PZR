#include "cmdcalc.h"

int main(int argc, char* argv[]) 
{
    //3 для выражения и 2 для ключа дешифрования
    if (argc < 5) 
    { 
        printf("Ошибка: недостаточно аргументов.\n");
        return 1;
    }

    // Проверяем наличие флага "-k"
    int key_index = -1;
    for (int i = 1; i < argc; i++) 
    {
        if (strcmp(argv[i], "-k") == 0) 
        {
            key_index = i;
            break;
        }
    }

    if (key_index == -1 || key_index + 1 >= argc) 
    {
        printf("Ошибка: отсутствует флаг '-k' или ключ дешифрования\n");
        return 1;
    }

    // Вычисляем количество выражений
    int expression_count = (key_index - 1) / 3;
    if ((key_index - 1) % 3 != 0) 
    {
        printf("Ошибка: некорректный формат ввода.\n");
        return 1;
    }

    // Читаем ключ дешифрования
    int key = atoi(argv[key_index + 1]);

    int* results = (int*)malloc(expression_count * sizeof(int));
    if (!results) 
    {
        printf("Ошибка: не удалось выделить память для результатов\n");
        return 1;
    }

    // Вычисляем результаты
    int result_count = 0;
    for (int i = 1; i < key_index; i += 3) 
    {
        int left_operand = atoi(argv[i]);
        char operator = argv[i + 1][0];
        int right_operand = atoi(argv[i + 2]);

        results[result_count++] = calculate(left_operand, operator, right_operand);
    }

    printf("Результаты вычислений:\n");
    for (int i = 0; i < result_count; i++) 
    {
        printf("Ответ №%d: %d\n", i + 1, results[i]);
    }

    char* decoded_string = (char*)malloc((result_count + 1) * sizeof(char));
    if (!decoded_string) 
    {
        printf("Ошибка: не удалось выделить память для дешифрованной строки\n");
        free(results);
        return 1;
    }

    print(result_count, decoded_string, results, key);

    printf("\n");

    free(results);
    free(decoded_string);

    return 0;
}