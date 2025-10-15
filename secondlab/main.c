#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 30

#ifdef _WIN32
    #include <windows.h>
#endif

void clear_console()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void fill_large_array(int array[])
{
    srand(time(NULL));

    for (int i = 0; i < N; ++i)
    {

        array[i] = rand() % 100;
    }
}

void fill_small_array(int array[], int size)
{
    for (int i = 0; i < size; ++i) 
    {
        scanf("%d", &array[i]);
    }
}

void output_array(int array[], int size)
{

    printf("Массив:\n");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int max_element(int array[], int size, int division)
{
    int i = 0; 
    int max_value = 1;

    while (i < size)
    {
        if (array[i] % division == 0 && array[i] > max_value)
        {
            max_value = array[i];
        }
        i++;
    }
    return max_value;
}

int first_even(int array[], int size)
{
    int index = -1;

    for (int i = 0; i < size; i++)
    {
        if (i != 0 && array[i] % 2 == 0)
        {
            index = i;
            i = size;
        }
    }

    return index;
}

int main()
{
    unsigned short isRunning = 1;
    while (isRunning)
    {
        clear_console();

        unsigned short choice;

        printf("Введите ваш выбор\n");
        printf("1. Создание массива из 30 случайных значений\n");
        printf("2. Заполнение массива 5 значениями через ввод\n");
        printf("3. Выход\n");

        printf("Введите ваш выбор: ");
        scanf(" %hu", &choice);

        switch (choice) 
        {
            case 1:
            {
                clear_console();
                int array[N];

                fill_large_array(array);
                output_array(array, N);

                int max_element_num = max_element(array, N, 4);
                if (max_element_num != 1)
                {
                    printf("Максимальный элемент в массиве, кратный 4: %d\n", max_element_num);
                }
                else
                {
                    printf("Не найдено элемента, кратного 4\n");
                }

                int first_even_num = first_even(array, N);
                if (first_even_num != -1)
                {
                    printf("Индекс первого чётного ненулевого элемента: %d\n", first_even_num);
                }
                else
                {
                    printf("Чётное число не найдено\n");
                }

                printf("\nНажмите Enter для продолжения\n");
                getchar();
                getchar();
                break;
            }

            case 2:
            {
                clear_console();

                int array[5];
                for (int i = 0; i < 5; ++i)
                {
                    printf("Введите %d число: ", i+1);
                    scanf(" %d", &array[i]);
                }

                output_array(array, 5);

                int max_element_num = max_element(array, 5, 4);
                if (max_element_num != 1)
                {
                    printf("Максимальный элемент в массиве, кратный 4: %d\n", max_element_num);
                }
                else
                {
                    printf("Не найдено элемента, кратного 4\n");
                }

                int first_even_num = first_even(array, 5);
                if (first_even_num != -1)
                {
                    printf("Индекс первого чётного ненулевого элемента: %d\n", first_even_num);
                }
                else
                {
                    printf("Чётное число не найдено\n");
                }

                printf("\nНажмите Enter для продолжения\n");
                getchar();
                getchar();
                break;
            }

            case 3:
            {
                char confirm;
                printf("Выйти? [y/n]: ");
                scanf(" %c", &confirm);

                if (confirm == 'y' || confirm == 'Y')
                {
                    isRunning = 0;
                }
                break;
            }
                
            default:
                printf("Совпадений не найдено\n");
                printf("\nНажмите Enter для продолжения\n");
                getchar();
                getchar();
                break;
        }
    }

    return 0;
}
