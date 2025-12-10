#include <stdio.h>

// Рекурсивная функция для 1 задания
int F(int n) {
    if (n < 2) {
        return 1;
    }
    if (n % 3 == 0) {
        return F(n / 3) + 1;
    } else {
        return F(n - 2) + 5;
    }
}

// Функция для 1 задания
// Считает количество нечётных цифр в числе number.
int countOddDigits(int number) {
    if (number == 0) {
        return 0;
    }
    
    int digit = number % 10;    // Получаем последнюю цифру
    
    int isOdd = (digit % 2 != 0) ? 1 : 0;
    
    return isOdd + countOddDigits(number / 10);
}


// Функция для 2 задания (Самый оптимальный вариант)
// a_{n+1} = a_n * ( (n+1) / (n*(2n+1)) * x^2 )
double calculate_series_recursive(double x, int N) {
    if (N <= 0) return 0.0;

    // 1. Начальный член при n=1: a_1 = 2*x
    double current_term = 2.0 * x;
    double total_sum = current_term;
    
    double x_squared = x * x;

    for (int n = 1; n < N; n++) {
        double coefficient = (double)(n + 1) / (n * (2 * n + 1));
        
        current_term = current_term * coefficient * x_squared;
        
        total_sum += current_term;
    }

    return total_sum;
}

int main() {
    // 1 задание 1 пункт
    // Найти количество n на отрезке [1; 100000], для которых F(n) равно 55.
    int counter = 0;
    for (int n = 1; n <= 100000; n++) {
        if (F(n) == 55) {
            counter++;
        }
    }
    
    printf("=== 1 Задание ===\n");
    printf("Задание 1: Количество n на отрезке [1; 100000], где F(n) = 55: %d\n", counter);

    // 1 задание 2 пункт
    // Количество нечётных цифр результата вычисления F(x), где x задает пользователь.
    int X;
    printf("\nЗадание 2: Введите число X: ");
    if (scanf("%d", &X) == 1) {
        int resultF = F(X);
        printf("Значение F(%d) = %d\n", X, resultF);
        
        int oddDigitsCount = countOddDigits(resultF);
        printf("Количество нечётных цифр в результате: %d\n", oddDigitsCount);
    } else {
        printf("Ошибка ввода числа.\n");
    }

    // 2 Задание 4 Вариант
    double x;
    int N;

    printf("\n=== 2 Задание ===\n");
    printf("Введите значение x: ");
    while (scanf("%lg", &x) != 1) {
        printf("Ошибка! Вы ввели не число. Попробуйте снова: ");
        while (getchar() != '\n');
    }

    printf("Введите количество членов N: ");
    while (scanf("%d", &N) != 1 || N <= 0) {
        printf("Ошибка ввода N (должно быть целое положительное число).\n");
        while (getchar() != '\n');
    }

    double result_rec = calculate_series_recursive(x, N);

    printf("\nРезультат:\n");
    printf("1. Рекуррентный метод: %.15lg\n", result_rec);
    
    return 0;
}
