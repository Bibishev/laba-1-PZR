#include "cmdcalc.h"

int main(int argc, char* argv[]) 
{
    //3 ��� ��������� � 2 ��� ����� ������������
    if (argc < 5) 
    { 
        printf("������: ������������ ����������.\n");
        return 1;
    }

    // ��������� ������� ����� "-k"
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
        printf("������: ����������� ���� '-k' ��� ���� ������������\n");
        return 1;
    }

    // ��������� ���������� ���������
    int expression_count = (key_index - 1) / 3;
    if ((key_index - 1) % 3 != 0) 
    {
        printf("������: ������������ ������ �����.\n");
        return 1;
    }

    // ������ ���� ������������
    int key = atoi(argv[key_index + 1]);

    int* results = (int*)malloc(expression_count * sizeof(int));
    if (!results) 
    {
        printf("������: �� ������� �������� ������ ��� �����������\n");
        return 1;
    }

    // ��������� ����������
    int result_count = 0;
    for (int i = 1; i < key_index; i += 3) 
    {
        int left_operand = atoi(argv[i]);
        char operator = argv[i + 1][0];
        int right_operand = atoi(argv[i + 2]);

        results[result_count++] = calculate(left_operand, operator, right_operand);
    }

    printf("���������� ����������:\n");
    for (int i = 0; i < result_count; i++) 
    {
        printf("����� �%d: %d\n", i + 1, results[i]);
    }

    char* decoded_string = (char*)malloc((result_count + 1) * sizeof(char));
    if (!decoded_string) 
    {
        printf("������: �� ������� �������� ������ ��� ������������� ������\n");
        free(results);
        return 1;
    }

    print(result_count, decoded_string, results, key);

    printf("\n");

    free(results);
    free(decoded_string);

    return 0;
}