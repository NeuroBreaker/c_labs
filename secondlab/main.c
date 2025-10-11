#include <stdio.h>
#include <stdlib.h>

#define N 26

void fill_large_array(int array[])
{
    unsigned int x;
    srand(x);

    for (int i = 0; i < N; ++i)
    {

        array[i] = rand() % 10;
    }
}

void fill_small_array(int array[])
{

    for (int i = 0; i < N; ++i) 
    {
        scanf("%d", &array[i]);
    }
}

void output_array(int array[])
{

    printf("Массив:\n");
    for (int i = 0; i < N; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

void find_max_even_num(int array[])
{

    int temp = 0;
    for (int i = 0; i < N; i++)
    {
        if (array[i] % 2 == 0) 
        {
            if (array[i] > temp)
            {
                temp = array[i];
            }
        }
    }
    printf("Максимальное чётное: %d\n", temp);
}

void find_last_odd_num(int array[])
{
    for (int i = N - 1; i >= 0; --i) {
        if (array[i] % 2 == 1 && array[i] % array[0] != 0)
        {
            printf("Последнее нечётное, не кратное первому элементу массива: %d\n", array[i]); 
            break;
        }
    }
}

int main()
{

    int array[N];

    if (N > 10)
    {
        fill_large_array(array);
    }
    else if (N > 0)
    {
        fill_small_array(array);
    }

    output_array(array);
    find_max_even_num(array);
    find_last_odd_num(array);
}
