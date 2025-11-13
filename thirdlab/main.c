#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>
#include <string.h>

#define LINES 5

/* 
        Лабораторная работа №3
        Вариант 6
*/

// Генерирует исходный файл через rand
int generate_source_file(const char* filename, int num_lines)
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

// Вывод всех символов из файла в консоль
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
    int counts[10] = {0};    

    for (int i = 0; line[i] != '\0'; i++) {
        int digit = line[i] - '0';
        if (digit >= 0 && digit <= 9)
        {
            counts[digit]++;
        }
    }

    // Формируем результат только для ненулевых счетчиков
    result[0] = '\0';
    int first = 1;
    
    for (int digit = 0; digit < 10; digit++) {
        if (counts[digit] > 0) {
            char temp[20];
            if (!first) {
                strcat(result, ", ");
            }
            sprintf(temp, "%d %d", digit, counts[digit]);
            strcat(result, temp);
            first = 0;
        }
    }
}

// Создаёт конечный файл
void build_result_file(const char* filename_source, const char* filename_result)
{
    FILE* source = fopen(filename_source, "r");
    if (!source) {
        printf("Ошибка открытия исходного файла %s\n", filename_source);
        return;
    }

    FILE* out = fopen(filename_result, "w");
    if (!out) {
        printf("Ошибка открытия результирующего файла %s\n", filename_result);
        fclose(source);
        return;
    }

    char line[20];
    char result[100];
    
    while (fgets(line, sizeof(line), source) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        
        count_chars_in_line(line, result);
        fprintf(out, "%s\n", result);
        printf("Строка: %s -> Результат: %s\n", line, result);
    }

    fclose(source);
    fclose(out);
}

int main()
{
    srand(time(NULL));

    const char dir_path[] = "files";
    const char filename_source[] = "files/source.txt";
    const char filename_result[] = "files/result.txt";

    printf("Создание директории files, если её не существует ...\n");
    if (mkdir(dir_path, 0755) == 0) {
        printf("Директория files успешно создана\n");
    }
    else {
        if (errno == EEXIST) {
            printf("Директория уже существует\n");
        }
        else {
            perror("Ошибка создания директории");
        }
    }

    printf("Генерация исходного файла ...\n");
    int error = generate_source_file(filename_source, LINES);

    if (error) {
        perror("Не удалось создать файл\n");
    }
    
    printf("Исходный файл:\n");
    output_file(filename_source, LINES);

    printf("\nСоздание результирующего файла...\n");
    build_result_file(filename_source, filename_result);
    
    printf("\nСодержимое результирующего файла:\n");
    output_file(filename_result, LINES);
}
