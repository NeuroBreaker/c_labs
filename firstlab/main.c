#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    Лабораторная работа №1 
    
    Вариант 5

*/

int exitf(int is_running) {
    while (is_running) {
        printf("\nВведите 1 для подтверждения выхода ...\n");

        scanf("%d", &is_running);
        if (is_running == 1) {
            is_running = 0;
        }
    }

    system("clear");
    printf("Программа завершена\n\n");

    return is_running;
}

void showMenu() {
    system("clear");

    printf("Выберите задание, решение которого\n");
    printf("необходимо продемострировать\n\n");
    printf("1. Нахождение площади\n");
    printf("2. Перевод килограмм в фунты\n");
    printf("3. Сумма цифр трёхзначного числа\n");
    printf("4. Найти значения функций\n");
    printf("5. Выход\n\n");
}

void first() {
    double outer_radius, inner_radius, ring_area;

    system("clear"); 

    printf("Введите внешний R1: ");
    scanf("%lf", &outer_radius);

    printf("\nВведите внутренний R2: ");
    scanf("%lf", &inner_radius);

    ring_area = M_PI * (outer_radius * outer_radius - inner_radius * inner_radius);
    printf("\nПлощадь кольца: %.2f\n", ring_area);

    int _exit = exitf(1);
}

void second() {
    float kg, funts;
    const double PI = 3.14;

    system("clear"); 
    printf("Перевод киллограммов в фунты\n");
    printf("Введите количество: ");
    scanf("%f", &kg);

    funts = kg * 2.2046;
    printf("%f\n\n", funts);

    int _exit = exitf(1);
}

void third() {
    int integer, firstNum, secondNum, thirdNum, sum;

    system("clear");
    printf("Введите трёхзначное число: ");
    scanf("%d", &integer);

    firstNum = integer % 1000 / 100;
    secondNum = integer % 100 / 10;
    thirdNum = integer % 10;

    sum = firstNum + secondNum + thirdNum;

    printf("Ваша сумма: %d\n\n", sum);
    
    int _exit = exitf(1);
}

void fourth() {
    double x;

    system("clear"); 

    printf("Введите значение x: ");
    scanf("%lf", &x);

    printf("Вычисляем две функции\n");

    double func1 = 0.25 * log((1 + x) / (1 - x)) + 0.5 * atan(x);
    printf("Первая функция: %lf\n", func1);

    double func2 = (1 + x) * exp(-x);
    printf("Вторая функция: %lf\n", func2);

    int _exit = exitf(1);
}


int run(int is_running) {
    int choice;

    showMenu();

    scanf("%d", &choice);
    switch (choice) {
        case 1:
            first();
            return 1;
        case 2:
            second();
            return 1;
        case 3:
            third();
            return 1;
        case 4:
            fourth();
            return 1;
        case 5:
            return exitf(is_running);
        default:
            return 0;
    }
}

int main() {
    int is_running = 1;
    while (is_running)
    {
        is_running = run(is_running);
    }

    return 0;
}
