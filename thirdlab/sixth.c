#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int generate_file(const char* filename, int num_lines)
{
    FILE* file = fopen(filename, "w");
    if (!file) {
        return 1;
    }

    for (int i = 0; i < num_lines; i++) {
        for (int j = 0; j < 10; j++)
        {
            int num = rand() % 10;
            fputc(num + '0', file);
        }
        fputc('\n', file);
    }

    fclose(file);
    return 0;
}

int output_file(const char* filename, int num_lines)
{
    FILE* file = fopen(filename, "r");
    if (!file) {
        return 1;
    }

    char ch;
    for (int i = 0; i < num_lines; i++) {
        for (int j = 0; j < 10; j++)
        {
            while ((ch = fgetc(file)) != EOF)
            {
                printf("%c", ch);
            }
        }
    }

    return 0;
}


void count_chars_in_line(const char* line, char* result)
{
    int counts[10] = {0}; // counts[0] для '0', counts[1] для '1', counts[2] для '2' и т.д.
    
    // Подсчет цифр 0, 1, 2, ..., 9
    for (int i = 0; line[i] != '\0'; i++) {
        int digit = line[i] - '0';
        if (digit >= 0 && digit <= 9)
        {
            counts[digit]++;
        }

        // Формируем результат только для ненулевых счетчиков
        int first = 1;
        char temp[20];
        
        if (counts[digit] > 0) {
            if (!first) {
                strcat(result, ", ");
            } 
            sprintf(temp, "0 %d", counts[0]);
            strcat(result, temp);
            first = 0;
        }

        result[0] = '\0'; // Очищаем строку результата
    }
}

int main()
{
    srand(time(NULL));

    const char filename[] = "source.txt";
    int error = generate_file(filename, 3);

    if (error)
    {
        printf("Не удалось создать файл\n");
    }

    int _error = output_file(filename, 3);
}
